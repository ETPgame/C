#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node {
	ElementType data;
	struct Node *next;
} QNode;
typedef struct {
	QNode *front; //¶ÓÊ×
	QNode *rear;  //¶ÓÎ²
} LinkQueue;

LinkQueue* createQueue(){
	LinkQueue *Q;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

int push(LinkQueue *Q, ElementType x) {
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (p == NULL) {
		return 0;
	} 
	else {
		if (Q->front == NULL) {
			Q->front = p;
			Q->rear = p;
		} else {
			Q->rear->next = p;
			Q->rear = p;
		}
		return 1;
	}
}
int empty(LinkQueue *Q)	{
	return Q->front == NULL ? 1 : 0;
}
int pop(LinkQueue *Q) {
	if (empty(Q))return 0;
	Q->front = Q->front->next ;
	return 1;
}
ElementType front(LinkQueue *Q) {
	return Q->front->data ;
}
void clearQueue(LinkQueue *Q) {
	QNode *p = Q->front ;
	QNode *q = p;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	Q->front = NULL;
	Q->rear = Q->front;
}
void destroyQueue(LinkQueue *Q) {
	QNode *p = Q->front ;
	QNode *q = p;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	free(Q);
}


int main() {

	return 0;
}
