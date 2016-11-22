%{
#include <stdio.h>
#include<stdlib.h>

int intAmount = 0, floatAmount = 0, idAmount = 0, errAmount = 0;

%}
%option noyywrap 
%%
[\+|\-]?[0-9]+; {
	printf("Find a Integer: %s\n",yytext);
	intAmount++;
}
[\+|\-]?[0-9]+[.][0-9]+; {
	printf("Find a Float: %s\n",yytext);
	floatAmount++;
}
[A-Z|a-z]{1}[_|A-Z|a-z|0-9]*; {
	printf("Find a ID: %s\n",yytext);
	idAmount++;	
}
\n {}
.+ {
	printf("Find a Error token: %s\n",yytext);
	errAmount++;	
}
%%
int main(){
	yylex();
	printf("Float Amount: %d\n", floatAmount);
	printf("Integer Amount: %d\n", intAmount);
	printf("ID Amount: %d\n", idAmount);
	printf("Err Amount: %d\n", errAmount);
	return 0;
}
