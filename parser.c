#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"
#define lenns 5 //how many branch can a node have at most

#define VALNUM 10
NodeData* newNodeData(char* c, char* k, char* d) {
	NodeData* nd = (NodeData*)malloc(sizeof(NodeData));
	nd->cate = c;
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
	auto void printPreorder(node * node);
	auto void func();
	int tCounter = 0;
	int fc = 0;
	NodeData* t = newNodeData("PROGRAM", "", "");
	node* head = newNode(t);
	//while (tokens[tCounter].keyword != NULL) {
	func();
	//}
	node* f = head->child;
	while (f) {
		printf("%s %s %s\n", f->nd->cate, f->nd->keyword, f->nd->data);
		printPreorder(f->child);
		f = f->next;
	}
	return head;
	void func() {
		auto int declared(char* variable, int vcount);
		auto void stat();
		int sc = 0;
		int vcount = 0;
		char** variables = malloc(VALNUM * sizeof(char*));
		if (strcmp(tokens[tCounter].keyword, "DATA_TYPE") != 0) fail(tCounter);
		if (strcmp(tokens[++tCounter].keyword, "IDENTIFIER") != 0) fail(tCounter);
		//add fuct node to head
		NodeData* f = newNodeData("FUNCTION", "", tokens[tCounter].data);
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
		//printf("%s %s\n", variables[0], variables[1]);
		fc++;
		void stat() {
			auto void expr(node* n);
			int ec = 0;
			//if (strcmp(tokens[tCounter].keyword, "RETURN") != 0) fail(tCounter);
			//add statements to functions
			node* snode;
			NodeData* s;
			if (strcmp(tokens[tCounter].keyword, "RETURN") == 0) {
				s = newNodeData("STATEMENT", "RETURN", tokens[tCounter].data);
				snode = addChild(fnode, s);
				tCounter++;
				while (strcmp(tokens[tCounter].keyword, "SEMI_COLON") != 0) {
					expr(snode);
				}
			}
			else if (strcmp(tokens[tCounter].keyword, "DATA_TYPE") == 0) {
				s = newNodeData("STATEMENT", "DATA_TYPE", tokens[tCounter].data);
				snode = addChild(fnode, s);
				tCounter++;
				s = newNodeData("STATEMENT", "IDENTIFIER", tokens[tCounter].data);
				if (!declared(tokens[tCounter].data, vcount)) {
					//strcpy(variables[vcount], tokens[tCounter].data);
					variables[vcount] = malloc(sizeof(char*) * 50 * VALNUM);
					strcpy(variables[vcount], tokens[tCounter].data);
					vcount++;
				}
				addChild(snode, s);
				tCounter++;
				if (strcmp(tokens[tCounter].keyword, "=") == 0) {
					if (strcmp(tokens[tCounter+1].keyword, "INT_LITERAL") && strcmp(tokens[tCounter + 1].keyword, "UNARY_OP")) fail(tCounter);
					s = newNodeData("STATEMENT", "=", tokens[tCounter].data);
					addChild(snode, s);
					tCounter++;
					while (strcmp(tokens[tCounter].keyword, "SEMI_COLON") != 0) {
						expr(snode);
					}
				}
				else if (strcmp(tokens[tCounter].keyword, ";") != 0) fail(tCounter);
			}
			//NodeData* s = newNodeData("STATEMENT", "", tokens[tCounter].data);
			
			//while (strcmp(tokens[tCounter].keyword, "SEMI_COLON") != 0) {
				//expr(snode);
			//}
			sc++;
			void expr(node* n) {
				//printf("%s %s", tokens[tCounter].keyword, tokens[tCounter + 1].keyword);
				if (strcmp(tokens[tCounter].keyword, "UNARY_OP") == 0) {
					NodeData* e = newNodeData("EXPRESSION", "UNARY_OP", tokens[tCounter].data);
					//node* enode = newNode(e);
					node* enode = addChild(n, e);
					tCounter++;
					expr(enode);
				}
				else {
					if (strcmp(tokens[tCounter].keyword, "INT_LITERAL") != 0) fail(tCounter);
					//add express
					NodeData * e = newNodeData("EXPRESSION", "INT_LITERAL", tokens[tCounter].data);
					addChild(n, e);
					tCounter++;
					ec++;
				}
			}
		}
		int declared(char* variable, int vcount) {
			for (int i = 0; i < vcount; i++) {
				if (strcmp(variable, variables[i]) == 0) {
					return 1;
				}
			}
			return 0;
		}
	}
	void printPreorder(node* node) {
		if (node == NULL)
			return;
		while (node)
		{
			if (node->child)
				//printf("new node");
				printPreorder(node->child);
			printf("%s %s %s\n", node->nd->cate, node->nd->keyword, node->nd->data);
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
