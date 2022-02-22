#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

int main() {
	auto void generator(node * node);
    char *filename = "return2.c";
	char* s = malloc(4096);
	char ini[300];
	sprintf(ini, ".file\t\"return2.c\"\n.text\n.section\t.text.startup, \"ax\", @progbits\n.p2align 4\n.globl\tmain\n.type\tmain, @function\nmain:\n");
	strcat(s, ini);
	generator(parser(lexer(reader(filename))));
	
	//parser(lexer(reader(filename)));
	//lexer(reader(filename));
	strcat(s, "\0");
	printf("%s", s);
	FILE *fptr = fopen("out.s", "w");
	// exiting program 
	if (fptr == NULL) {
		printf("Error!");
		exit(1);
	}
	fputs(s, fptr);
	fclose(fptr);
	/*
	void expression(node * node) {
		if (strcmp(node->nd->keyword, "INT_LITERAL") == 0) {
			char str[20];
			sprintf(str, "movl\t$%s, %%eax\n", node->nd->data);
			//\nret
			strcat(s, str);
		}
		else if (strcmp(node->nd->keyword, "UNARY_OP") == 0) {
			expression(node->next);
			char str[20];
			sprintf(str, "movl\t$%s, %%eax\n", node->nd->data);
			//\nret
			strcat(s, str);
		}
	}
	*/
	void generator(node * n) {
		if (n == NULL)
			return;
		while (n)
		{
			if (n->child)
				generator(n->child);
			char str[20];
			//printf("%s %s\n", node->nd->keyword, node->nd->data);
			if (strcmp(n->nd->cate, "PROGRAM") == 0) {
			}
			else if (strcmp(n->nd->cate, "FUNCTION") == 0) {
				//strcat(s, n->nd->data);
				//strcat(s, ":\n");
				//printf("%s printed function ", s);
			}
			else if (strcmp(n->nd->cate, "STATEMENT") == 0 && strcmp(n->nd->keyword, "RETURN") == 0) {
				sprintf(str, "ret\n");
				strcat(s, str);
			}
			else if (strcmp(n->nd->cate, "EXPRESSION") == 0) {
				if (strcmp(n->nd->keyword, "INT_LITERAL") == 0) {
					sprintf(str, "movl\t$%s, %%eax\n", n->nd->data);
					strcat(s, str);
				}
				else if (strcmp(n->nd->keyword, "UNARY_OP") == 0) {
					if (strcmp(n->nd->data, "~") == 0) {
						sprintf(str, "not\t%%eax\n");
						strcat(s, str);
					}
					else if (strcmp(n->nd->data, "-") == 0) {
						sprintf(str, "neg\t%%eax\n");
						strcat(s, str);
					}
					else if (strcmp(n->nd->data, "!") == 0) {
						sprintf(str, "cmpl\t$0, %%eax\n");
						strcat(s, str);
						sprintf(str, "movl\t$0, %%eax\n");
						strcat(s, str);
						sprintf(str, "sete\t%%al\n");
						strcat(s, str);
					}
				}
			}
			n = n->next;
		}
	}
    return 0;
}
