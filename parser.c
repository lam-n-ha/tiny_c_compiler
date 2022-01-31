#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"
int parse(Token *token) {
	int k = 0;
}
void fail() {
	printf("fail");
}
void func() {
	printf(".globl _main\n_main:\n");
}
void ret(char val[]) {
	printf("movl $%s, %%eax\nret", val);
}