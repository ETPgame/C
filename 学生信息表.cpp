#include<bits/stdc++.h>
using namespace std;
#define M 30
typedef struct DATA{
	char id[M];
	char name[M];
	char sex;
	float a,b,c,sum;
}Data;
typedef struct NODE{
	Data data;
	struct NODE *next;
}Node;
void read(Data *t){
	scanf("%s %s %c %f%f%f",t->id ,t->name ,&(t->sex ),&(t->a ),&(t->b )
	,&(t->c ));
}
void write(Data *t){
	printf("%s %s %c ",t->id ,t->name ,t->sex );
	printf("%.1lf %.1lf %.1lf\n",t->a ,t->b ,t->c );
	
}
Node *find (Node*head,char id[]){
	Node*p=head;
	for(p=head->next;p!=NULL;p=p->next){
		if(strcmp(p->data.id,id)==0){
			return p;
		}
	}
	return NULL;
}
Node *findpre (Node*head,Node*p){
	Node*q=head;
	for(q=head;q!=NULL;q=q->next){
		if(q->next==p){
			return q;
		}
	}
	return NULL;
}
void Insert(Node*head){
	Node *p=(Node*)malloc(sizeof(Node));
	Node *tail=head;
	Node *q=NULL;
	p->next =NULL;
	printf("Insert:\n");
	read(&(p->data ));
	q=find(head,p->data.id );
	if(q==NULL){
		while(tail->next !=NULL){
			tail=tail->next ;
		}
		write(&(p->data ));
		tail->next =p;
	}
	else{
		printf("Failed\n");
	}
	
}
void Quit(Node *head){
	printf("Good bye!\n");
	Node *p=head;
	while(head->next !=NULL){
		p=head;
		head=head->next ;
		free(p);
	}
	free(head);
	exit(0);
}
void sort (Node*head){
	Node *p=NULL,*q=NULL;
	Data t;
	for(p=head->next;p!=NULL;p=p->next ){
		for(q=p->next ;q!=NULL;q=q->next ){
			if(strcmp(p->data.id,q->data.id)>0){
				t=p->data ;
				p->data =q->data ;
				q->data =t;
			}
		}
	}
}
void List (Node *head){
	Node *p=NULL;
	printf("List:\n");
	sort(head);
	for(p=head->next;p!=NULL;p=p->next  ){
		write(&(p->data));
	}
}

void Find (Node* head){
	Node*p=head;
	char id[M];
	printf("Find:\n");
	scanf("%s",id);
	p=find(head ,id);
	if(p==NULL){
		printf("Failed\n");
	}
	else{
		write(&(p->data));
	}
}
void Change(Node*head){
	Node*p=NULL;
	Data t;
	read(&t);
	printf("Change:\n");
	p=find(head,t.id);
	if(p==NULL){
		printf("Failed\n");
	}
	else{
		p->data=t;
		write(&(p->data));
	}
}
void Delete(Node*head){
	Node*p=NULL;
	Node*q=NULL;
	char id[M];
	printf("Delete:\n");
	scanf("%s",id);
	p=find(head,id);
	if(p==NULL){
		printf("Failed\n");
	}
	else{
		q=findpre(head,p);
		q->next=p->next;
		free(p);
		printf("Deleted\n");
	}
}
int main(){
	char cmd[M];
	Node *head=NULL;
	int *p=NULL;
	p=(int *)malloc(sizeof(int));
	head=(Node*)malloc(sizeof(Node));
	head->next =NULL;
	
	while(1){
		scanf("%s",&cmd);
		switch(cmd[0]){
			case 'I':
				Insert(head);
				break;
			case 'L':
				List(head);
				break;
			case 'F':
				Find(head);
				break;
			case 'C':
				Change(head);
				break; 
			case 'D':
				Delete(head);
				break;
			case 'Q':
			case 'E':
				Quit(head);
		}
	}
	return 0;
}
