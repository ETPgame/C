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
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
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
