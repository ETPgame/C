#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node, *LinkStack;

LinkStack createStack(){
	LinkStack top;
	top=(LinkStack)malloc(sizeof(Node));
	top->next =NULL;
	return top;
}

int push(LinkStack S, ElementType x){
	LinkStack p=(LinkStack)malloc(sizeof(Node));
	p->data =x;
	p->next= S->next ;
	S->next =p;
	return 1;
}
int empty(LinkStack S){
	if(S->next ==NULL){
		return 1;
	} 
	return 0; 
}
int pop(LinkStack S){
	LinkStack p=S->next ;
	ElementType x;
	if(S->next ==NULL){
		return 0;
	}
	else{
		S->next =p->next ;
		x=p->data ;
		free(p);
		return x;
	}
}
ElementType getTop(LinkStack S){
	return S->next ->data;
}
void clearStack(LinkStack S){
	LinkStack p=S->next ;
	while(p!=NULL){
		S->next =p->next ;
		free(p);
		p=S->next ;
	}
}
void destroyStack(LinkStack S){
	LinkStack p=S ;
	while(p!=NULL){
		S->next =p->next ;
		free(p);
		p=S->next ;
	}	
}
int main()
{
	char ch[100];
	int i,k,j,temp;
	char l;
	i=k=j=temp=0;
	LinkStack S,W;
	scanf("%s",ch);
	while(ch[i]!='\0'){
		if(ch[i]>='0'&&ch[i]<='9'){
			push(S,(ch[i]));
		}
		if(ch[i]=='('){
			push(W,(ch[i]));
		}
		else if(ch[i]==')'){
			while((l=pop(W))!='(')
			j=pop(S);
			k=pop(S);
			if(l=='+'){
				temp=j+k;
			}
			else if(l=='-'){
				temp=k-j;
			} 
			else if(l=='*'){
				temp=j*k;
			}
			else{
				temp=k/j;
			}
			push(S,temp);
		}
		else if(ch[i]=='*'){
			l=pop(W);
			if(l=='('||l=='+'||l=='-'){
				push(W,ch[i]);
			}
			else{
				j=pop(S);
				k=pop(S);
				temp=j*k;
				push(S,temp);
			}
		}
		else if(ch[i]=='/'){
			l=pop(W);
			if(l=='('||l=='+'||l=='-'){
				push(W,ch[i]);
			}
			else{
				j=pop(S);
				k=pop(S);
				temp=k/j	;
				push(S,temp);
			}			
		}
		else if(ch[i]=='+'){
			i=pop(S);
			j=pop(S);
			temp=i+j;
			push(S,temp);
		}
		else if(ch[i]=='-'){
			i=pop(S);
			j=pop(S);
			temp=i-j;
			push(S,temp);
		}
	}
	printf("%d\n",getTop(S));
    return 0;
}







