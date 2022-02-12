#define lenns 5 //how many branch can a node have at most
typedef struct Token {
	char keyword[20];
	char data[100];
} Token;
typedef struct NodeData {
	char keyword[20];
	char data[100];
} NodeData;
typedef struct node node;
struct node {
	NodeData nd;
	struct node* ns[lenns];
};
char* reader(char* filename);
Token* lexer(char* file);
node* parser(Token* tokens);