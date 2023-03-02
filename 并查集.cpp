#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
	int * parent;
	int size;
}SNode,* Set;

Set createSet(int size){
	Set p=(Set)malloc(sizeof(SNode));
	p->size=size;
	p->parent=(int*)malloc(sizeof(int)*(size+1));
	return p;
}
void initSet(Set S){
	for(int i=0;i<S->size;i++){
		S->parent[i]=-1;
	}
}
int findSet(Set S,int x){
	int r=x;
	while(S->parent[r]!=-1){
		r=S->parent[r];
	}
	int t;
	while(S->parent[x]!=-1){
		t=S->parent[x];
		S->parent[x]=r;
		x=t;
	}
	return r;
}
void unionSet(Set S,int x,int y){
	int rx=findSet(S,x);
	int ry=findSet(S,y);
	if(rx!=ry){
		S->parent[rx]=ry;
		//TODO
	}
}
void destroySet(Set S){
	if(S!=NULL){
		free(S->parent);
		free(S);
		//TODO
	}
}
int main()
{
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
	return 0;
}
