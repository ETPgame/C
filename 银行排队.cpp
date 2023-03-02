#include<bits/stdc++.h>
#define M 30
using namespace std;
int a=0,b=0;
typedef struct DATA{
	int num;
	char id[M];
	char type[M];
	int sum;
}Data;
typedef struct NODE{
	Data data;
	struct NODE *next;
}Node;
void read(Data*t){
	scanf("%s%s",t->id,t->type);
	a++;
	b++;
	t->num=a;
	t->sum=b-1;
}
void write(Data*t){
	printf("%d %s %s %d\n",t->num,t->id,t->type,t->sum);
}
void sort(Node*head,Node *p){
	Node *tail=head->next;//第一个Ordinary 
	Node *tailpro=head;//最后一个 VIP 
	int temp,i;
	Node *q;
	if(head->next ==NULL){
		head->next =p;
	}
	else if(strcmp(p->data.type ,"VIP")==0){//p是VIP 

		while(strcmp(tail->data.type ,"VIP")==0){
			tailpro=tail;//最后一个VIP 
			tail=tail->next ;
		}
		tailpro->next =p;
		p->next =tail;
		temp=p->data.sum;
		p->data.sum =tail->data.sum ;
		tail->data.sum =temp;
		q=tail;
		tail=tail->next ;
		while(tail!=NULL){
			temp=tail->data.sum ;
			tail->data.sum =q->data.sum ;
			q->data.sum =temp;
			q=tail;
			tail=tail->next ;
		}
	}
	else{
		while(tail->next!=NULL){
			tail=tail->next;
		}
		tail->next=p;
	}
}
void In(Node*head){
	Node*p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	printf("IN:");
	read(&(p->data));
	sort(head,p); 
	write(&(p->data));
}
void Quit(Node*head){
	printf("GOOD BYE!\n");
	Node*p=head;
	while(head->next!=NULL){
		p=head;
		head=head->next;
		free(p);
	}
	free(head);
	exit(0);
}
void OUT(Node*head){
	Node *p=head->next;
	Node * q=p;
	if(head->next==NULL){
		printf("FAILED:\n");
	}
	else{
		printf("OUT:");
		printf("%d %s %s\n",head->next->data.num,head->next->data.id,head->next->data.type);
		head->next=p->next;
		for(q=p;q!=NULL;q=q->next){
			q->data.sum-=1;
		}
		b--;
		free(p);
	}
}
void List (Node *head){
	Node *p=NULL;
	printf("LIST:\n");
	for(p=head->next;p!=NULL;p=p->next  ){
		printf("%d %s %s\n",p->data.num,p->data .id,p->data .type);
	}
}
int main(){
	char cmd[M];
	Node *head=(Node*)malloc(sizeof(Node));
	head->next =NULL;
	while(1){
		scanf("%s",&cmd);
		switch(cmd[0]){
			case 'I':
				In(head);
				break;
			case 'L':
				List(head);
			 	break;
			case 'Q':
				Quit(head);
			case 'O':
				OUT(head);
				break;
		}
	}
	
	return 0;
}
