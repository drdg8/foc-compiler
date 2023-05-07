%{
#include <iostream>
#include <string>
#include "ast.hpp"
#include "parser.hpp"
#define SAVE_IDENTIFIER  yylval.sVal = new std::string(yytext, yyleng)
#define SAVE_DOUBLE  yylval.dVal = stod(new std::string(yytext, yyleng))
#define SAVE_INTEGER  yylval.iVal = stoi(new std::string(yytext, yyleng))
#define TOKEN(t)    (yylval.token = t)
%}

%option noyywrap

%%

[ \t\n]					        ;//匹配回车
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"						 ; //匹配注释

"extern"                return TOKEN(TEXTERN);//c语言关键字
"return"				        return TOKEN(TRETURN);
"for"                   return TOKEN(FOR);
"if"                    return TOKEN(IF);
"else"                  return TOKEN(ELSE);
"while"                 return TOKEN(WHILE);
"switch"                return TOKEN(SWITCH);
"case"                  return TOKEN(CASE);
"default"               return TOKEN(DEFAULT);
"array"               return TOKEN(ARRAY);
"const"                return TOKEN(CONST);
"int"                   return TOKEN(INT);
"char"                  return TOKEN(CHAR);
"float"                 return TOKEN(FLOAT);
"double"                return TOKEN(DOUBLE);
"void"                  return TOKEN(VOID);
"bool"                  return TOKEN(BOOL);
"long"                  return TOKEN(LONG);
"continue"              return TOKEN(CONTINUE);
"until"                 return TOKEN(UNTIL);
"break"                 return TOKEN(BREAK);

[a-zA-Z_][a-zA-Z0-9_]*  {SAVE_IDENTIFIER; return TIDENTIFIER;}//标识符
[0-9]+\.[0-9]* 			    {SAVE_DOUBLE; return TDOUBLE;}//浮点
[0-9]+					        {SAVE_INTEGER; return TINTEGER;}//整型

"&&"                    return TOKEN(AND);//逻辑运算符
"||"                    return TOKEN(OR); 
"^"                     return TOKEN(BXOR);
"~"                     return TOKEN(BNOT);


"="						          return TOKEN(TEQUAL);//赋值和比较
"=="				          	return TOKEN(TCEQ);
"!="			          		return TOKEN(TCNE);
"<"				          		return TOKEN(TCLT);
"<="	          				return TOKEN(TCLE);
">"				          		return TOKEN(TCGT);
">="					          return TOKEN(TCGE);


"("	          					return TOKEN(TLPAREN);//括号
")"					          	return TOKEN(TRPAREN);
"["                     return TOKEN(TLBRACK);
"]"                     return TOKEN(RLBRACK);
"{"         						return TOKEN(TLBRACE);
"}"					          	return TOKEN(TRBRACE);



"+"				          		return TOKEN(TPLUS);//算术运算符
"-"		          				return TOKEN(TMINUS);
"*"		          				return TOKEN(TMUL);
"/"				          		return TOKEN(TDIV);


"."         						return TOKEN(TDOT);//其他
","				          		return TOKEN(TCOMMA);
"&"				          		return TOKEN(GAD);//取地址
";"				          		return TOKEN(SEMI);
":"                     return TOKEN(COLON);
"->"					          return TOKEN(ARW);//箭头（暂未实现）


.                       printf("Unknown token!\n"); yyterminate();

%%
