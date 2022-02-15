#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* reader(char* filename)
//void main()
char* reader(char* filename)
{
    char *file = malloc(4096);
    //char *file = fileString;
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    size_t read;
    fp = fopen(filename, "r");
    //fp = fopen("return2.c", "r");
    if (fp == NULL) {
        printf("fail to open file");
        return("");
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s\n", line);
        strcat(file, line);
        //printf("%s\n", fileString);
    }
    fclose(fp);

    //printf("%s", file);
    if (line)
        free(line);
    return file;
}