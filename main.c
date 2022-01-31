#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

int main() {
    char *filename = "return2.c";
    lexer(reader(filename));
    return 0;
}