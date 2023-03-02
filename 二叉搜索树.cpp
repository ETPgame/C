#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node{
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
}BSTNode, *BSTree;
BSTree newNode(ElementType x){
	BSTree p=(BSTree)malloc(sizeof(BSTNode));
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}

BSTree insert(BSTree bst, ElementType x){//非递归
	BSTree s,pre,p;
	s=newNode(x);
	p=bst;
	if(bst==NULL){
		bst=s;
		return bst;
	}
	while(p!=NULL){
		pre=p;
		if(x<p->data){
			p=p->lchild;
		}
		else if(x>p->data){
			p=p->rchild;
		}
		else{
			break;
		}
	}
	if(x<pre->data){
		pre->lchild=s;
 	}
	else if(x>pre->data){
		pre->rchild=s;
	}
	return bst;
}
BSTree Tinsert(BSTree bst, ElementType x){//递归插入
	if(bst==NULL){
		bst=newNode(x);
	}
	else if(x<bst->data){
		bst->lchild=insert(bst->lchild,x);
	}
	else if(x>bst->data){
		bst->rchild=insert(bst->rchild,x);//TODO
	}
	return bst;
}
void inOrder (BSTree bst){
	if(bst!=NULL){
		inOrder(bst->lchild);
		printf("%d ",bst->data);
		inOrder(bst->rchild);
	}
}
BSTNode* findMin(BSTree bst){
	BSTree p;
	if(bst==NULL){
		return NULL;
	}
	p=bst;
	while(p->lchild!=NULL){
		p=p->lchild;
	}
	return p;
}
BSTNode* findMax(BSTree bst){
	BSTree p;
	if(bst==NULL){
		return NULL;
	}
	p=bst;
	while(p->rchild!=NULL){
		p=p->rchild;
	}
	return p;
}
BSTNode* find(BSTree bst,ElementType x){
	BSTree p;
	p=bst;
	while(p!=NULL&&x!=p->data){
		if(x<p->data){
			p=p->lchild;
		}
		else if(x>p->data){
			p=p->rchild;
		}
	}
	return p;
}
BSTree deleteNode(BSTree bst, ElementType x){
	BSTree p;
	p=find(bst,x);
	if(p==NULL){
		return bst;
	}
	if(x<bst->data){
		bst->lchild=deleteNode(bst->lchild,x);
	}
	else if(x>bst->data){
		bst->rchild=deleteNode(bst->rchild,x);  
	}
	else if(x==bst->data){
		if(bst->lchild!=NULL&&bst->rchild!=NULL){
			p=findMin(bst->rchild);//TODO
			bst->data=p->data;
			bst->rchild=deleteNode(bst->rchild,bst->data);
		}
		else{
			p=bst;
			if(bst->lchild==NULL){
				bst=bst->rchild;
			}
			else if(bst->rchild==NULL){
				bst=bst->lchild;
			}
			free(p);
		}
	}
	return bst;
}
BSTree destroyBSTree(BSTree bst){
	if(bst==NULL){
		return NULL;
	}
	destroyBSTree(bst->lchild);
	destroyBSTree(bst->rchild);
	free(bst);
}
int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
