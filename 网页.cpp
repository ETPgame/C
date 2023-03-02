#include<bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef struct Node {
	ElementType data[70];
	struct Node *next;
} Node, *LinkStack;
LinkStack S;
LinkStack temp;
LinkStack createStack() {
	LinkStack top = new Node;
	top->next = NULL;
	return top;
}
int empty(LinkStack S) {
	return S->next == NULL;
}
int push(LinkStack S, ElementType x[]) {
	LinkStack p = new Node;
	if (p == NULL) return 0;
	strcpy(p->data, x);
	p->next = S->next;
	S->next = p;
	return 1;
}
int pop(LinkStack S) {
	LinkStack p;
	p = S->next;
	if (p == NULL)return 0;
	S->next = p->next;
	delete p;
	return 1;
}
ElementType* getTop(LinkStack S) {
	return S->next->data;
}
void clearStack(LinkStack S) {
	S->next = NULL;
}
void destroyStack(LinkStack S) {
	clearStack(S);
	delete S;
}
int scount = 0, tempcount = 0;
int main() {
	char ins[10];
	S = createStack();
	temp = createStack();
	while (1) {
		scanf("%s", ins);
		if (strcmp(ins, "VISIT") == 0) {
			char web[50];
			scanf("%s", web);
			push(S, web);
			printf("%s\n", web);
			clearStack(temp);
			scount++;
			tempcount = 0;
		} else if (strcmp(ins, "BACK") == 0) {
			if (scount <= 1) {
				printf("Ignored\n");
			} else {
				push(temp, getTop(S));
				pop(S);
				printf("%s\n", getTop(S));
				tempcount++;
				scount--;
			}
		} else if (strcmp(ins, "FORWARD") == 0) {
			if (tempcount < 1) {
				printf("Ignored\n");
			} else {
				push(S, getTop(temp));
				pop(temp);
				printf("%s\n", getTop(S));
				tempcount--;
				scount++;
			}
		} else if (strcmp(ins, "QUIT") == 0) {
			return 0;
		}
	}
}
