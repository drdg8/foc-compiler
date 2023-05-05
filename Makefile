all : c_compiler
LLVM_CONFIG = /usr/bin/llvm-config-14

CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`

OBJS = parser.o lexer.o ast.o CodeGenerator.o main.o 

parser.cpp: src/parser.y 
	bison -d -o $@ $^

parser.hpp: parser.cpp

lexer.cpp: src/lexer.l src/parser.hpp
	flex -o $@ $^

%.o: src/%.cpp src/ast.hpp src/CodeGenerator.hpp
	g++ -c $(CXXFLAGS) -g -o $@ $< 

c_compiler: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

clean:
	$(RM) -rf src/parser.cpp src/parser.hpp src/c_compiler src/lexer.cpp $(OBJS) 