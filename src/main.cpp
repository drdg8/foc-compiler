#include "CodeGenerator.hpp"
#include "ast.hpp"
#include <llvm/Support/TargetSelect.h>
#include <iostream>
#include <fstream>


extern int yyparse(void);
extern BlockNode* programBlock;

int main(int argc, const char* argv[]){
    if(argc == 1){
        std::cout << "Usage :" <<std::endl;
        std::cout << "\t -i 指定输入文件" <<std::endl;
        std::cout << "\t -o 制定输出文件 默认:a.o" <<std::endl;
    }
    std::string InputFile;
    std::string OutputObjectFile;	
    
    
}