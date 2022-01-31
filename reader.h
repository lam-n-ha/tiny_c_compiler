typedef struct Token {
	char keyword[20];
	char data[100];
	//char* keyword;
	//char* data;
} Token;

char* reader(char* filename);
Token* lexer(char* file);