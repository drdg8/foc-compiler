#include "CodeGenerator.hpp"
#include "ast.hpp"
#include <llvm/Support/TargetSelect.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
#include <iostream>
#include <fstream>


extern int yyparse(void);
extern Block* programBlock;

 //存储参数
std::vector<std::string> args;
std::map<std::string, std::string> argMap;

void parseArgments(){
    for (int i = 0; i < args.size(); i++){
        if (args[i][0] == '-'){
            std::string name(&args[i][1]);

            if (i + 1 < args.size() && args[i + 1][0] != '-') {
                argMap[name] = args[i + 1];
                i++;
            }
            else {
                argMap[name] = "";
            }
        }
    }
}


int main(int argc, const char* argv[]){
    if(argc == 1){
        std::cout << "Usage :" <<std::endl;
        std::cout << "\t -i 指定输入文件" <<std::endl;
        std::cout << "\t -o 制定输出文件 默认:a.o" <<std::endl;
    }
   
    for (int i = 0; i < argc; i++){
        args.push_back(argv[i]);
    }

    //分离选项和选项内容
    parseArgments();
    std::string InputFile;
    std::string OutputObjectFile;	
    
    //处理输入文件
    auto it_0 = argMap.find("i");
    if(it_0 == argMap.end())
        std::cout << "error：无输入文件" << std::endl;
    InputFile = it_0->second;
    freopen(InputFile.c_str(), "r", stdin);

    
    //处理输出文件
    auto it_1 = argMap.find("o");
    if(it_1 == argMap.end() )
        OutputObjectFile = "a.ll";
    else{
        OutputObjectFile = it_1->second;
        if(OutputObjectFile.length() <= 3 || OutputObjectFile.substr(OutputObjectFile.length() - 3) != ".ll")
        {
            OutputObjectFile = OutputObjectFile + ".ll";
        }
        
    }    
    //处理-s选项
    auto it_s = argMap.find("s");
    if(it_s != argMap.end()){
        std::string OutputAssemblyFile = it_s->second;
        if(OutputAssemblyFile.length() <= 2 || OutputAssemblyFile.substr(OutputAssemblyFile.length() - 2) != ".s")
        {
            OutputAssemblyFile = OutputAssemblyFile + ".s";
        }
        
        // Convert LLVM IR to RISC-V assembly code
        std::string command = "llc -march=riscv32 " + OutputObjectFile + " -filetype=asm -o " + OutputAssemblyFile;
        system(command.c_str());
    }


    std::cout <<OutputObjectFile << std::endl;
    yyparse();
    CodeGenerator* generator = new CodeGenerator();
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmParser();
    llvm::InitializeNativeTargetAsmPrinter();

    std::cout<<"program begin"<<std::endl;
    generator->GenerateCode(programBlock);

    auto it_O = argMap.find("O");
    if(it_O != argMap.end()){
        unsigned optLevel = stoi(it_O->second);

        // 创建优化器
        llvm::legacy::PassManager pm;
        llvm::PassManagerBuilder pmb;
        pmb.OptLevel = optLevel;
        pmb.populateModulePassManager(pm);

        // 运行优化器
        pm.run(*(generator->Module));
    }

    //将目标代码写入output file中
    generator->GenIR(OutputObjectFile);

    
}