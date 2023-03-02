#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
	ElementType data;
	struct Node *lchild;
	struct Node *rchild;
}BTNode,*BTree;
BTree create(){
	char ch;
	BTree rt;
	ch=getchar();
	if(ch=='.'){
		return NULL;
	}
	else{
		rt=(BTree)malloc(sizeof(BTNode));
		rt->data=ch;
		rt->lchild=create();
		rt->rchild=create();
		return rt;
	}
}
int getLeafNum(BTree rt){
	if(rt==NULL){
		return 0;
	} 
	if(rt->lchild ==NULL&&rt->rchild ==NULL){
		return 1;
	}
	return getLeafNum(rt->lchild )+getLeafNum(rt->rchild );
}
void leafNode(BTree rt){
	if(rt!=NULL){
		if(rt->lchild ==NULL&&rt->rchild ==NULL){
			printf("%c",rt->data );
		}
		leafNode(rt->lchild );
		leafNode(rt->rchild );
	}
}
int getDepth(BTree rt){
	int ldepth,rdepth,depth;
	if(rt==NULL){
		return 0;
	}
	rdepth=getDepth(rt->rchild);
	ldepth=getDepth(rt->lchild);
	depth=max(rdepth,ldepth)+1;
	return depth;
}
int getNum(BTree rt){
	if(rt==NULL){
		return 0;
	}
	else{	
		return getNum(rt->rchild)+getNum(rt->lchild)+1;
	}
}
void preOrderExt(BTree bt){
	if(bt==NULL){
		printf(".");
		return ;
		//TODO
	}
	printf("%c",bt->data);
	preOrderExt(bt->lchild);
	preOrderExt(bt->rchild);
}	
void InOrderExt(BTree bt){
	if(bt==NULL){
		return;
	}
	InOrderExt(bt->lchild);
	printf("%c",bt->data);
	InOrderExt(bt->rchild);
}	
void printTree(BTree bt,int num){
	if(bt==NULL){
		return;
		//TODO
	}
	printTree(bt->rchild,num+1);
	for(int i=0;i<num;i++){
		printf("-");
	}
	printf("%c",bt->data);
	printf("\n");
	printTree(bt->lchild,num+1);
	
}
int main()
{
	BTree rt=(BTree)malloc(sizeof(BTNode));
	rt=create();
	printTree(rt,0);
	return 0;
}
void layerOrder(BTree bt){
	BTree t;
	queue <BTree> q;
	q.push(bt);
	while(!q.empty()){
		t=q.front();
		q.pop();
		printf("%c",t->data );
		if(t->lchild !=NULL){
			q.push(t->lchild); 
		}
		if(t->rchild !=NULL){
			q.push(t->rchild );
		}
	}
}

