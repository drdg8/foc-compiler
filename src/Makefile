all : c_compiler

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`

OBJS = parser.o lexer.o ast.o CodeGenerator.o main.o 

parser.cpp: parser.y 
	bison -d -o $@ $^

parser.hpp: parser.cpp

lexer.cpp: lexer.l parser.hpp
	flex -o $@ $^

%.o: %.cpp ast.hpp CodeGenerator.hpp
	g++ -c $(CPPFLAGS) -g -o $@ $< -I /usr/include/llvm-14 -I /usr/include/llvm-c-14
c_compiler: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS) -I /usr/include/llvm-14 -I /usr/include/llvm-c-14

clean:
	$(RM) -rf parser.cpp parser.hpp c_compiler lexer.cpp $(OBJS) 