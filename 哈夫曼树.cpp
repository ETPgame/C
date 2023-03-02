#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef struct
{
	KeyType value;
	int weight;
} Node;

typedef struct HTNode
{
	KeyType value; //节点数值
	int weight;  //节点权
	HTNode * lchild;
	HTNode * rchild;
	int depth;
	bool operator < (const HTNode &a)const
	{
		return weight < a.weight||(weight==a.weight&&value < a.value);
	}
} HTNode, *HuffmanTree;

typedef HuffmanTree ElementType;
typedef struct
{
	ElementType * data; //数据
	int size;	 		//大小
	int capacity;  		//容量
} HNode, *Heap;
int left(int i){
	return i*2;
}
int right(int i){
	return i*2+1;
}
int parent(int i){
	return i/2;
}
void swap(Heap H,int i,int j){
	ElementType t;
	t=H->data[i];
	H->data[i]=H->data[j];
	H->data[j]=t;
}
void heapify(Heap H,int i){
	int l,r;
	int smallest;
	l=left(i);
	r=right(i);
	smallest=i;
	if(l<=H->size&&*(H->data[l])<*(H->data[i]))
		smallest=l;
	if(r<=H->size&&*(H->data[r])<*(H->data[smallest]))
		smallest=r;
	if(smallest!=i){
		swap(H,i,smallest);
		heapify(H,smallest);
	}
}
void initHeap(Heap H,Node data[],int n){
	int i;
	HTNode *p=NULL;
	for(i=1;i<=n;i++){
		p=(HTNode*)malloc(sizeof(HTNode));
		p->value=data[i].value;
		p->weight=data[i].weight;
		p->lchild=NULL;
		p->rchild=NULL;
		H->data[i]=p;
	}
	H->size=n;
	for(i=n/2;i>=1;i--){
		heapify(H,i);
	}
}	
ElementType front(Heap H){
	return H->data[1];
}	
void push(Heap H,ElementType x){
	H->size++;
	int i=H->size;
	H->data[i]=x;
	while(i>1&&*(H->data[i])<*(H->data[parent(i)])){
		swap(H,i,parent(i));
		i=parent(i);
	}
}
void pop(Heap H){
	H->data[1]=H->data[H->size];
	H->size--;
	heapify(H,1);
}
Heap createHeap(int capacity){
	Heap p=(Heap)malloc(sizeof(HNode));
	p->size=capacity;
	p->size=0;
	p->data=(ElementType*)malloc(sizeof(ElementType)*(capacity+1));
	return p;
}
void destroyHeap(Heap H){
	if(H!=NULL){
		free(H->data);
		free(H);//TODO
	}
}		
HuffmanTree createHuffmanTree(Node data[],int n){
	Heap H=createHeap(n);
	initHeap(H,data,n);
	HTNode *p,*q,*t;
	for(int i=1;i<n;i++){
		p=front(H);
		pop(H);
		q=front(H);
		pop(H);
		t=(HTNode*)malloc(sizeof(HTNode));
		t->lchild=p;
		t->rchild=q;
		t->value=min(p->value,q->value);
		t->weight=p->weight+q->weight;
		push(H,t);
		//TODO
	}
	HuffmanTree HT=front(H);
	destroyHeap(H);
	return HT;
}
void huffmanCode(HuffmanTree HT,int code[],int depth){
	if(HT==NULL)return;
	if(HT->lchild==NULL&&HT->rchild==NULL){
		printf("%d:",HT->value);
		for(int i=0;i<depth;i++){
			printf("%d",code[i]);
		}
		printf("\n");
		return;
	}
	if(HT->lchild!=NULL){
		code[depth]=0;
		huffmanCode(HT->lchild,code,depth+1);
	}
	if(HT->rchild!=NULL){
		code[depth]=1;
		huffmanCode(HT->rchild,code,depth+1);
	}
}
void initDepth(HuffmanTree HT,int depth){
	if(HT==NULL){
		return ;
		//TODO
	}
	HT->depth=depth;
	initDepth(HT->lchild,depth+1);
	initDepth(HT->rchild,depth+1);
}
int getWPL(HuffmanTree HT){
	if(HT==NULL)
		return 0;
	if(HT->lchild==NULL&&HT->rchild==NULL){
		return HT->weight*HT->depth;
		//TODO
	}
	return getWPL(HT->lchild)+getWPL(HT->rchild);
}
int main()
{
	int code[100]={0};
	Node data[10];
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&data->value,&data->weight);
	}
	HuffmanTree HT=createHuffmanTree(data,n);
	int depth=0;
	initDepth(HT,depth);
	j=getWPL(HT);
	printf("%d\n",j);
	huffmanCode(HT,code,depth);
	return 0;
}
