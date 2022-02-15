#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

int main() {
	auto void generator(node * node);
    char *filename = "return2.c";
	char* s = malloc(4096);
	char ini[300];
	sprintf(ini, ".file\t\"return2.c\"\n.text\n.section\t.text.startup, \"ax\", @progbits\n.p2align 4\n.globl\tmain\n.type\tmain, @function\n");
	strcat(s, ini);
	generator(parser(lexer(reader(filename))));

	//parser(lexer(reader(filename)));
	//lexer(reader(filename));
	strcat(s, "\0");
	printf("%s", s);
	FILE *fptr = fopen("assembly.s", "w");
	// exiting program 
	if (fptr == NULL) {
		printf("Error!");
		exit(1);
	}
	fputs(s, fptr);
	fclose(fptr);
	void generator(node * node) {
		if (node == NULL)
			return;
		while (node)
		{
			//printf("%s %s\n", node->nd->keyword, node->nd->data);
			if (strcmp(node->nd->keyword, "PROGRAM") == 0) {
			}
			else if (strcmp(node->nd->keyword, "FUNCTION") == 0) {
				strcat(s, node->nd->data);
				strcat(s, ":\n");
				//printf("%s printed function ", s);
			}
			else if (strcmp(node->nd->keyword, "STATEMENT") == 0) {
			}
			else if (strcmp(node->nd->keyword, "EXPRESSION") == 0) {
				char str[20];
				sprintf(str, "movl\t$%s, %%eax\nret\n", node->nd->data);
				strcat(s, str);
				//printf("%s", s);
			}
			if (node->child)
				generator(node->child);
			node = node->next;
		}
	}
    return 0;
}
