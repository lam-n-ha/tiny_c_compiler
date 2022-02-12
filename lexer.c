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
		if ((s[i] != '(') && (s[i] != ')') && (s[i] != '{') && (s[i] != '}') && (s[i] != ';')) {
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
	char* pre;
	char pret[100][80];
	pre = strtok(str, delim);
	int counter = 0;
	while (pre != NULL) {
		strcpy(pret[counter], pre);
		pre = strtok(NULL, delim);
		counter++;
	}
	strcpy(pret[counter++], "\0");
	Token* tokens = malloc(counter * sizeof(*tokens));
	i = 0;
	while (pret[i][0] != '\0') {
		strncpy(tokens[i].data, pret[i], strlen(pret[i]));
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
		else if (isNumber(pret[i]) == 1) {
			strcpy(tokens[i].keyword, "INT_LITERAL");
		}
		else {
			strcpy(tokens[i].keyword, "IDENTIFIER");
		}
		printf("%s\t%s\t%s\n", pret[i], tokens[i].data, tokens[i].keyword);
		i++;
	}
	//func();
	//ret(pret[6]);
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
