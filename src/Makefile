all : c_compiler

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`
INCLUDE = -I `$(LLVMCONFIG) --includedir`

OBJS = parser.o lexer.o ast.o CodeGenerator.o main.o 

parser.cpp: parser.y 
	bison -d -o $@ $^

parser.hpp: parser.cpp

lexer.cpp: lexer.l parser.hpp
	flex -o $@ $^

%.o: %.cpp ast.hpp CodeGenerator.hpp
	g++ -c $(CPPFLAGS) -g -o $@ $< $(INCLUDE)

c_compiler: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS) $(INCLUDE)

clean:
	$(RM) -rf parser.cpp parser.hpp c_compiler lexer.cpp $(OBJS) 
