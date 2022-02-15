#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"
#define lenns 5 //how many branch can a node have at most

NodeData* newNodeData(char* k, char* d) {
	NodeData* nd = (NodeData*)malloc(sizeof(NodeData));
	nd->keyword = k;
	nd->data = d;
	return (nd);
}
node* newNode(NodeData* data) {
	node* n = (node*)malloc(sizeof(node));
	n->nd = data;
	return (n);
}
node* addSib(node* n, NodeData* data) {
	if (n == NULL)
		return NULL;
	while (n->next)
		n = n->next;
	return (n->next = newNode(data));
}
node* addChild(node* n, NodeData* data) {
	if (n == NULL)
		return NULL;
	// Check if child list is not empty.
	if (n->child)
		return addSib(n->child, data);
	else
		return (n->child = newNode(data));
}
void fail(int i) {
	printf("fail at token %d", i);
	exit(0);
}
node* parser(Token* tokens) {
	//for (int j = 0; j < 9; j++) {
		//printf("%s %s\n", tokens[j].keyword, tokens[j].data);
	//}
	//auto void printPreorder(node * node);
	auto void func();
	int tCounter = 0;
	int fc = 0;
	NodeData* t = newNodeData("PROGRAM", "");
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
		NodeData* f = newNodeData("FUNCTION", tokens[tCounter].data);
		//NodeData* f = malloc(sizeof(f));;
		//strcpy(f->keyword, "FUNCTION");
		//strcpy(f->data, tokens[tCounter].data);
		node* fnode = addChild(head, f);
		//head->ns[fc] = newNode(f);
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
			NodeData* s = newNodeData("STATEMENT", tokens[tCounter].data);
			//NodeData* s = malloc(sizeof(s));
			//strcpy(s->keyword, "STATEMENT");
			//strcpy(s->data, tokens[tCounter].data);
			node* snode = addChild(fnode, s);
			//head->ns[fc]->ns[sc] = newNode(s);
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
				NodeData* e = newNodeData("EXPRESSION", tokens[tCounter].data);
				//NodeData* e = malloc(sizeof(e));
				//strcpy(e->keyword, "FUNCTION");
				//strcpy(e->data, tokens[tCounter].data);
				addChild(snode, e);
				//head->ns[fc]->ns[sc]->ns[ec] = newNode(f);
				//printf("expression node created");
				ec++;
			}
		}
	}
	void printPreorder(node* node) {
		if (node == NULL)
			return;
		while (node)
		{
			printf("%s %s\n", node->nd->keyword, node->nd->data);
			if (node->child)
				printPreorder(node->child);
			node = node->next;
		}
	}
}

//void func() {
	//printf(".globl _main\n_main:\n");
//}
//void ret(char val[]) {
	//printf("movl $%s, %%eax\nret", val);
//}
