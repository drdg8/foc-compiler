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
"return"				        return TOKEN(RETURN);
"for"                   return TOKEN(FOR);
"if"                    return TOKEN(IF);
"else"                  return TOKEN(ELSE);
"while"                 return TOKEN(WHILE);
"switch"                return TOKEN(SWITCH);
"case"                  return TOKEN(CASE);
"default"               return TOKEN(DEFAULT);
"continue"              return TOKEN(CONTINUE);
"break"                  printf("break_lex\n"); return TOKEN(BREAK);

"int"													{return TOKEN(INT); }
"char"													{return TOKEN(CHAR); }
"double"												{return TOKEN(DOUBLE); }
"void"													{return TOKEN(VOID); }

[a-zA-Z_][a-zA-Z0-9_]*  {SAVE_IDENTIFIER;  return IDENTIFIER;}//标识符
[0-9]+\.[0-9]* 			    {SAVE_DOUBLE; return REAL;}//浮点
[0-9]+					        {SAVE_INTEGER; return INTEGER;}//整型
\'.\'|\'\\.\'         {SAVE_CHAR; return CHARACTER;}//字符
\"(\\.|[^"\\])*\"       {SAVE_STRING; return STRING; }//字符串
"&&"                    return TOKEN(AND);//逻辑运算符
"||"                    return TOKEN(OR); 
"^"                     return TOKEN(XOR);
"~"                     return TOKEN(NOT);


"="						       { return TOKEN(EQUAL);}//赋值和比较
"=="				          	return TOKEN(CEQ);
"!="			          		return TOKEN(CNE);
"<"				          		return TOKEN(CLT);
"<="	          				return TOKEN(CLE);
">"				          		return TOKEN(CGT);
">="					          return TOKEN(CGE);


"("	          					return TOKEN(LPAREN);//括号
")"					          	return TOKEN(RPAREN);
"["                     return TOKEN(LBRACK);
"]"                     return TOKEN(RBRACK);
"{"         					  return TOKEN(LBRACE);
"}"					          	return TOKEN(RBRACE);



"+"				          		return TOKEN(PLUS);//算术运算符
"-"		          				return TOKEN(MINUS);
"*"		          				return TOKEN(MUL);
"/"				          		return TOKEN(DIV);


"."         						return TOKEN(DOT);
","				          		return TOKEN(COMMA);
"&"				          		return TOKEN(GAD);//取地址
";"				          	  	 return TOKEN(SEMI);
":"                     return TOKEN(COLON);

[ \t\n]				         //匹配回车
"//"[^\n]*                                //匹配单行注释
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"						 ; //匹配注释


.                       printf("Unknown token!\n"); yyterminate();

%%
