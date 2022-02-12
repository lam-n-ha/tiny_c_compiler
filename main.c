#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

int main() {
	auto void generator(node * node);
    char *filename = "return2.c";
	char* s = "";
    generator(parser(lexer(reader(filename))));
	void generator(node * node) {
		if (node == NULL)
			return;
		printf("%s %s ", node->nd.data, node->nd.keyword);
		if (strcmp(node->nd.keyword, "PROGRAM")) {
		}
		else if (strcmp(node->nd.keyword, "FUNCTION")) {
			strcat(s, node->nd.data);
			strcat(s, ":");
		}
			int i = 0;
			while (node->ns[i] != NULL) {
				generator(node->ns[i]);
				i++;
			}
	}
	//printf("%s", s);
    return 0;
}
