#define lenns 5 //how many branch can a node have at most
typedef struct Token {
	char* keyword;
	char* data;
} Token;
typedef struct NodeData {
	char* cate;
	char* keyword;
	char* data;
} NodeData;
typedef struct node {
	NodeData* nd;
	//struct node* ns[lenns];
	struct node* child;
	struct node* next;
} node;
char* reader(char* filename);
Token* lexer(char* file);
node* parser(Token* tokens);