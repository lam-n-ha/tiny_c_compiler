#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"
#define lenns 5 //how many branch can a node have at most
node* newNode(NodeData data)
{
    node* n = (node*)malloc(sizeof(node));
    n->nd = data;
	for (int i = 0; i < lenns; i++) {
		n->ns[i] = NULL;
	}
    return (n);
}
void fail(int i);
node* parser(Token* tokens) {	
	auto void printPreorder(node * node);
	auto void func();
	int tCounter = 0;
	int fc = 0;
	NodeData t;
	strcpy(t.keyword, "PROGRAM");
	node* head = newNode(t);
	//while (tokens[tCounter].keyword != NULL) {
	func();
	//}
	//printPreorder(head);
	return head;
	void func() {
		auto void stat();
		int sc = 0;
		if (strcmp(tokens[tCounter].keyword, "DATA_TYPE") != 0) fail(tCounter);
		if (strcmp(tokens[++tCounter].keyword, "IDENTIFIER") != 0) fail(tCounter);
		//add fuct node to head
		NodeData f;
		strcpy(f.keyword, "FUNCTION");
		strcpy(f.data, tokens[tCounter].data);
		head->ns[fc] = newNode(f);
		//printf("function node created");
		//printf("%s:\n", tokens[tCounter].data);
		if (strcmp(tokens[++tCounter].keyword, "OPEN_PARENT") != 0) fail(tCounter);
		if (strcmp(tokens[++tCounter].keyword, "CLOSE_PARENT") != 0) fail(tCounter);
		//printf("%s %s", tokens[tCounter].keyword, tokens[tCounter + 1].keyword);
		if (strcmp(tokens[++tCounter].keyword, "OPEN_BRACKET") != 0) fail(tCounter);
		tCounter++;
		while (strcmp(tokens[tCounter].keyword, "CLOSE_BRACKET") != 0) {
			stat();
			tCounter++;
		}
		fc++;
		void stat() {
			auto void expr();
			int ec = 0;
			if (strcmp(tokens[tCounter].keyword, "RETURN") != 0) fail(tCounter);
			//add statements to functions
			NodeData s;
			strcpy(s.keyword, "STATEMENT");
			strcpy(s.data, tokens[tCounter].data);
			head->ns[fc]->ns[sc] = newNode(s);
			//printf("statement node created");
			tCounter++;
			while (strcmp(tokens[tCounter].keyword, "SEMI_COLON") != 0) {
				expr();
				tCounter++;
			}
			sc++;
			void expr() {
				//printf("%s %s", tokens[tCounter].keyword, tokens[tCounter + 1].keyword);
				if (strcmp(tokens[tCounter].keyword, "INT_LITERAL") != 0) fail(tCounter);
				//add express
				NodeData e;
				strcpy(f.keyword, "FUNCTION");
				strcpy(f.data, tokens[tCounter].data);
				head->ns[fc]->ns[sc]->ns[ec] = newNode(f);
				//printf("expression node created");
				ec++;
			}
		}
	}
	void printPreorder(node* node) {
		if (node == NULL)
			return;
		printf("%s %s ", node->nd.data, node->nd.keyword);
		int i = 0;
		while (node->ns[i] != NULL) {
			printPreorder(node->ns[i]);
			i++;
		}
	}
}
void fail(int i) {
	printf("fail %d", i);
	exit(0);
}
//void func() {
	//printf(".globl _main\n_main:\n");
//}
//void ret(char val[]) {
	//printf("movl $%s, %%eax\nret", val);
//}