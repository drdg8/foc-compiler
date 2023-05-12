#include "CodeGenerator.hpp"
#include "ast.hpp"
#include <llvm/Support/TargetSelect.h>
#include <iostream>
#include <fstream>


extern int yyparse(void);
extern BlockNode* programBlock;

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
    auto it = argMap.find("i");
    if(it == argMap.end())
        std::cout << "error：无输入文件" << std::endl;
    
}