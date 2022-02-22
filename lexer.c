#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "reader.h"
int isNumber(char[]);
Token* lexer(char* file)
{
	char* s = file;
	char str[160] = "";
	int i = 0;
	int j = 0;
	while (i < 80) {
		if ((s[i] != '(') && (s[i] != ')') && (s[i] != '{') 
			&& (s[i] != '}') && (s[i] != ';') && (s[i] != '!')
			&& (s[i] != '~') && (s[i] != '-')) {
			str[j] = s[i];
			i++;
			j++;
		}
		else {
			str[j] = ' ';
			str[j + 1] = s[i];
			str[j + 2] = ' ';
			j = j + 3;
			i++;
		}
	}
	char delim[] = " \n\t\r";
	char *pre;
	char pret[100][100];
	pre = strtok(str, delim);
	int counter = 0;
	while (pre != NULL) {
		strcpy(pret[counter], pre);
		//printf("%s\n", pret[counter]);
		pre = strtok(NULL, delim);
		counter++;
	}

	Token* tokens = malloc(counter * sizeof *tokens);

	for (i = 0; i < counter; i++) {
		tokens[i].data = (char*)malloc(sizeof(char*));
		tokens[i].keyword = (char*)malloc(sizeof(char*));
		strcpy(tokens[i].data, pret[i]);
		if (strcmp(pret[i], "{") == 0) {
			strcpy(tokens[i].keyword, "OPEN_BRACKET");
		}
		else if (strcmp(pret[i], "}") == 0) {
			strcpy(tokens[i].keyword, "CLOSE_BRACKET");
		}
		else if (strcmp(pret[i], "(") == 0) {
			strcpy(tokens[i].keyword, "OPEN_PARENT");
		}
		else if (strcmp(pret[i], ")") == 0) {
			strcpy(tokens[i].keyword, "CLOSE_PARENT");
		}
		else if (strcmp(pret[i], ";") == 0) {
			strcpy(tokens[i].keyword, "SEMI_COLON");
		}
		else if (strcmp(pret[i], "int") == 0) {
			strcpy(tokens[i].keyword, "DATA_TYPE");
		}
		else if (strcmp(pret[i], "return") == 0) {
			strcpy(tokens[i].keyword, "RETURN");
		}
		else if (strcmp(pret[i], "!") == 0 || strcmp(pret[i], "~") == 0 || strcmp(pret[i], "-") == 0) {
			strcpy(tokens[i].keyword, "UNARY_OP");
		}
		else if (isNumber(pret[i]) == 1) {
			strcpy(tokens[i].keyword, "INT_LITERAL");
		}
		else if (strcmp(pret[i], "=") == 0) {
			strcpy(tokens[i].keyword, "=");
		}
		else {
			strcpy(tokens[i].keyword, "IDENTIFIER");
		}
		printf("%d\t%s\t%s\t%s\n", i, pret[i], tokens[i].data, tokens[i].keyword);
	}
	//printf("done lexing 1");
	return tokens;
}
int isNumber(char s[])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
			return 0;
	}
	return 1;
}