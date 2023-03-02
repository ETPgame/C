#include <bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct CSNode
{
	ElementType data;
	struct CSNode * child;
	struct CSNode * sibling;
}CSTNode,*CSTree;
CSTree NewNode(ElementType x){//创建节点
	CSTree p=(CSTree)malloc(sizeof(CSTNode));
	p->data=x;
	p->child=NULL;
	p->sibling=NULL;
	return p;
}
CSTree createTree(char s[]){
	int i,k,top;
	CSTree path[100],p;
	CSTree t;
	k=0;
	top=-1;
	for(i=0;s[i]!='\0';i++){
		if(isalpha(s[i])){
			p=(CSTree)malloc(sizeof(CSTNode));
			p->data=s[i];
			p->child=NULL;
			p->sibling=NULL;
			if(k==0)
				path[0]=p;
			else if(k==1)
				path[top]->child=p;
			else if(k==2){
				t=path[top]->child;
				while(t->sibling!=NULL)
					t=t->sibling;
				t->sibling=p;
			}
		}
		else{
			switch (s[i]) {
			case '(':
				++top;
				path[top]=p;
				k=1;
				break;
			case ',':
				k=2;
				//TODO
				break;
			case ')':
				top--;
				break;
			}
		}
	}
	return path[0];
}
CSTree CcreateTree(){
	char a,buf[100];
	scanf("%c",&a);
	getchar();
	CSTree root=NewNode(a);
	CSTree u,p,t;
	queue<CSTree> q;
	q.push(root);
	while(!q.empty()){
		u=q.front();
		q.pop();
		gets(buf);
		if(buf[0]=='#')
			continue;
		p=NewNode(buf[0]);
		u->child=p;
		q.push(p);
		for(int i=1;buf[i]!='#';i++){
			p=NewNode(buf[i]);
			q.push(p);
			t=u->child;
			while(t->sibling!=NULL)
				t=t->sibling;
			t->sibling=p;
		}
	}
	return root;
}
void postOrder(CSTree root){
	CSTree p;
	if(root!=NULL){
		postOrder(root->child);
		if(root->child!=NULL){
			for(p=root->child->sibling;p!=NULL;p=p->sibling){
				postOrder(p);
			}
		}
		printf("%c",root->data);
	}
}
void proOrder(CSTree root){
	CSTree p;
	if(root!=NULL){
		printf("%c",root->data);
		proOrder(root->child);
		if(root->child!=NULL){
			for(p=root->child->sibling;p!=NULL;p=p->sibling){
				proOrder(p);
			}
		}
	}
}
int main()
{
	char s[100];
	gets(s);
	createTree(s);
	return 0;
}
