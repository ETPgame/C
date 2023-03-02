#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node{
	ElementType data;
	struct Node  *next;
}Node, *LinkList;

LinkList createList(){
	Node* L=(LinkList)malloc(sizeof(LinkList));
	L->next=NULL;
	return L;
}
void printList(LinkList L){
	Node *p=L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int getLength(LinkList L){
	LinkList p=L->next;
	int cnt=0;
	while(p!=NULL){
		cnt++;
		p=p->next;
	}
	return cnt;
}
void insertHead(LinkList L,ElementType x){
	Node *p=(LinkList)malloc(sizeof(LinkList));
	p->data=x;
	p->next=L->next;
	L->next=p;
}

void insertTail(LinkList L,ElementType x){
	Node *p=(LinkList)malloc(sizeof(LinkList));
	Node *i;
	i=L;
	while(i->next!=NULL){
		i=i->next;
	}
	i->next=p;
	p->data=x;
	p->next=NULL;
}
Node*find (LinkList L,ElementType x){
	LinkList p;
	p=L->next;
	while(p->next !=NULL){
		if(p->data ==x){
			return p ;
		}	
		p=p->next ;
		
	}
	return NULL;
}
Node* locate (LinkList L,int i){
	Node*p=L->next ;
	int k;
	k=1;
	while(p!=NULL){
		if(k==i){
			return p;
		}
		p=p->next;
		k++; 
	}
	return NULL;
}
int insertList(LinkList L,int i,ElementType x){
	Node*p ;
	Node*s=(Node*)malloc(sizeof(Node*));
	p=locate(L,i-1);
	if(p==NULL||i<1){
		return 0;
	}
	s=(LinkList)malloc(sizeof(Node));
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}
int delNode (LinkList L,ElementType x){
	LinkList p,la;
	p=L;
	la=L;
	while(p!=NULL){
		if(p->data ==x){
			la->next =p->next ;
			free(p);
			return 1 ;
		}
		la=p;
		p=p->next ;
		
	}
	return 0;
}
int delNode(LinkList L,int i ,ElementType *px){
	LinkList p,la;
	int j=0;
	p=L;
	la=L;
	if(i<1){
		return 0;
	}
	while(p!=NULL&&j<i){
		la=p;
		p=p->next ;
		j++;
	}
	if(p==NULL){
		return 0;
	}
	
	la->next =p->next ;
	*px=p->data ;
	free(p);
	return 1;
}
void clearList(LinkList L){
	LinkList p,i;
	i=p=L->next;
	while(p!=NULL){
		i=p->next;
		free(p);
		p=i;
	}
	L->next=NULL;
}
void destroyList(LinkList L){
	LinkList p,i;
	p=L;
	i=p;
	while(p!=NULL){
		i=p->next;
		free(p);
		p=i;
	}
}
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
