#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* reader(char* filename)
void main()
{
    char* file;
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    size_t read;

    //fp = fopen(filename, "r");
    fp = fopen("return2.c", "r");
    if (fp == NULL) {
        printf("fail to open file");
        exit(EXIT_FAILURE);
        //return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s", line);
        strcat(file, line);
    }
    fclose(fp);
    if (line)
        free(line);
    printf("%s", file);
    //return file;
    exit(EXIT_SUCCESS);
}