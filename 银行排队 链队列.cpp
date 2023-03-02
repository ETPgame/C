#include<bits/stdc++.h>
using namespace std;
#define M 30
typedef struct ElementType{
	int num;
	char id[M];
	char type[M];
}ElementType;
typedef struct QNode
{
    ElementType data;
    struct QNode *next;
} QNode;
typedef struct LinkQueue
{
    QNode *front; //¶ÓÊ×
    QNode *rear;  //¶ÓÎ²
} Q;
void read(ElementType *t){
	scanf("%s %s",t->id ,t->type );
	t->num ++;
}
void write(ElementType *t){
	printf("%d %s %s %d\n",t->num ,t->id ,t->type ,t->num -1);
}
void Insert(LinkQueue*Q){
	QNode *p=(QNode*)malloc(sizeof(QNode));
	read(&(p->data ));
	printf("IN:");
	if(Q->front ==NULL){
		Q->front=p;
		Q->rear =Q->front ;
	}
	else{
		Q->rear->next =p;
		Q->rear =p;
	}
	write(&(Q->rear->data) );
}
void Quit(LinkQueue*Q){
	printf("GOOD BYE!\n");
	QNode *p=Q->front ;
	while(p!=NULL){
		Q->front=p->next ;
		free(p);
		p=Q->front ;
	}
	exit(0);
}
int main(){
	char cmd[M];
	LinkQueue *Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Q->front =Q->rear =NULL;
	while(1){
		scanf("%s",&cmd);
		switch(cmd[0]){
			case 'I':
				Insert(Q);
				break;
			case 'Q':
				Quit(Q);
		}
	}
} 
