%{
#include <iostream>
#include <string>
#include "ast.hpp"
//#include "parser.hpp"
extern "C" int yywrap() { }
#define SAVE_IDENTIFIER  yylval.sVal = new std::string(yytext, yyleng)
#define SAVE_DOUBLE  yylval.dVal = stod(new std::string(yytext, yyleng))
#define SAVE_INTEGER  yylval.iVal = stoi(new std::string(yytext, yyleng))
#define TOKEN(t)    (yylval.token = t)
%}

%option noyywrap

%%

[ \t\n]					        ;
"/*"[^*]*[*]+([^*/][^*]*[*]+)*"/"						 ; 
"extern"                        return TOKEN(TEXTERN);
"return"				        return TOKEN(TRETURN);
"for"                   return TOKEN(FOR);
"if"                    return TOKEN(IF);
"else"                  return TOKEN(ELSE);
"do"                    return TOKEN(DO);
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
[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]* 			    SAVE_TOKEN; return TDOUBLE;
[0-9]+					        SAVE_TOKEN; return TINTEGER;

"="						          return TOKEN(TEQUAL);
"=="				          	return TOKEN(TCEQ);
"!="			          		return TOKEN(TCNE);
"<"				          		return TOKEN(TCLT);
"<="	          				return TOKEN(TCLE);
">"				          		return TOKEN(TCGT);
">="					          return TOKEN(TCGE);

"("	          					return TOKEN(TLPAREN);
")"					          	return TOKEN(TRPAREN);
"["                     return TOKEN(TLBRACK);
"]"                     return TOKEN(RLBRACK);
"{"         						return TOKEN(TLBRACE);
"}"					          	return TOKEN(TRBRACE);

"->"					          return TOKEN(ARW);
"^"                     return TOKEN(BXOR);
"~"                     return TOKEN(BNOT);
"."         						return TOKEN(TDOT);
","				          		return TOKEN(TCOMMA);

"+"				          		return TOKEN(TPLUS);
"-"		          				return TOKEN(TMINUS);
"*"		          				return TOKEN(TMUL);
"/"				          		return TOKEN(TDIV);

.                       printf("Unknown token!\n"); yyterminate();

%%
