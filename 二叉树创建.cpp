#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
	ElementType data;
	struct Node *lchild;
	struct Node *rchild;
}BTNode,*BTree;

BTree createTree(char s[]);

int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
BTree createTree(char s[]){
	int k=0;
	int top=-1;
	BTNode *p,*path[100];
	for(int i=0;s[i]!='\0';i++){
		if(isalpha(s[i])){
			p=(BTNode*)malloc(sizeof(BTNode));
			p->rchild=NULL;
			p->lchild=NULL;
			p->data=s[i];
			if(k==0){
				path[0]=p;
			}
			if(k==1){
				path[top]->lchild=p;
			}
			if(k==2){
				path[top]->rchild=p;
			}
		}
		switch (s[i]){
			case '(':
				top++;
				path[top]=p; 
				k=1;
				break;
			case ',':
				k=2;
				break;
			case ')':
				top--;
				break;
		}
	}
	return path[0];
}
