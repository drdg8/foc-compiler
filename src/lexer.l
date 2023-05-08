%{
#include <iostream>
#include <string>
#include "ast.hpp"
#include "parser.hpp"
#define SAVE_IDENTIFIER  yylval.sVal = new std::string(yytext, yyleng)
#define SAVE_DOUBLE  yylval.dVal = stod(std::string(yytext, yyleng))
#define SAVE_INTEGER  yylval.iVal = stoi(std::string(yytext, yyleng))
#define SAVE_CHAR     yylval.cVal = yytext[1]
#define SAVE_STRING     yylval.strVal = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)
%}

%option noyywrap

%%

[ \t\n]					        ;//匹配回车
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"						 ; //匹配注释

"extern"                return TOKEN(EXTERN);//c语言关键字
"return"				        return TOKEN(RETURN);
"for"                   return TOKEN(FOR);
"if"                    return TOKEN(IF);
"else"                  return TOKEN(ELSE);
"while"                 return TOKEN(WHILE);
"switch"                return TOKEN(SWITCH);
"case"                  return TOKEN(CASE);
"default"               return TOKEN(DEFAULT);
"array"               return TOKEN(ARRAY);
"continue"              return TOKEN(CONTINUE);
"until"                 return TOKEN(UNTIL);
"break"                 return TOKEN(BREAK);

[a-zA-Z_][a-zA-Z0-9_]*  {SAVE_IDENTIFIER; return IDENTIFIER;}//标识符
[0-9]+\.[0-9]* 			    {SAVE_DOUBLE; return DOUBLE;}//浮点
[0-9]+					        {SAVE_INTEGER; return INTEGER;}//整型
\'"[^\\']"\'          {SAVE_CHAR; return CHARACTER;}//字符
\"(\\.|[^"\\])*\"       {SAVE_STRING; return STRING; }//字符串
"&&"                    return TOKEN(AND);//逻辑运算符
"||"                    return TOKEN(OR); 
"^"                     return TOKEN(XOR);
"~"                     return TOKEN(NOT);


"="						          return TOKEN(EQUAL);//赋值和比较
"=="				          	return TOKEN(CEQ);
"!="			          		return TOKEN(CNE);
"<"				          		return TOKEN(CLT);
"<="	          				return TOKEN(CLE);
">"				          		return TOKEN(CGT);
">="					          return TOKEN(CGE);


"("	          					return TOKEN(LPAREN);//括号
")"					          	return TOKEN(RPAREN);
"["                             return TOKEN(LBRACK);
"]"                             return TOKEN(RBRACK);
"{"         					return TOKEN(LBRACE);
"}"					          	return TOKEN(RBRACE);



"+"				          		return TOKEN(PLUS);//算术运算符
"-"		          				return TOKEN(MINUS);
"*"		          				return TOKEN(MUL);
"/"				          		return TOKEN(DIV);


"."         						return TOKEN(DOT);//其他
","				          		return TOKEN(COMMA);
"&"				          		return TOKEN(GAD);//取地址
";"				          		return TOKEN(SEMI);
":"                     return TOKEN(COLON);
"->"					          return TOKEN(ARW);//箭头（暂未实现）


.                       printf("Unknown token!\n"); yyterminate();

%%
