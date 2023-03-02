#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
	ElementType *data; //数据
	int size;	 		//大小
	int capacity;  		//容量
}HNode, *Heap;

Heap createHeap(int capacity){
	Heap p=(Heap)malloc(sizeof(HNode));
	p->capacity=capacity;
	p->size=0;
	p->data=(ElementType*)malloc(sizeof(ElementType)*(capacity+1));
	return p;
}
int parent(int i){
	return i/2;
}
int left(int i)	{
	return i*2;
}
int right(int i){
	return i*2+1;
}
int full(Heap H){
	if(H->capacity==H->size){
		return 1;
	}
	return 0;
}
int empty(Heap H){
	if(H->size==0){
		return 1;
	}
	return 0;
}
void swap(Heap H, int i, int j){
	ElementType t;
	t=H->data[i];
	H->data[i]=H->data[j];
	H->data[j]=t;
}
void increase(Heap H, int i, ElementType x){
	if(H->data[i]<x){
		H->data[i]=x;
		while(i>1&&H->data[parent(i)]<H->data[i]){
			swap(H,i,parent(i));
			i=parent(i);
		}//TODO
	}
}
int insert(Heap H, ElementType x){
	if(H->size==H->capacity){
		return 0;
		//TODO
	}
	H->size++;
	int i=H->size;
	H->data[i]=x;
	while(i>1&&H->data[parent(i)]<H->data[i]){
		swap(H,i,parent(i));
		i=parent(i);
		//TODO
	}
	return 1;
}
void heapify(Heap H,int i){
	int l,r;
	int largerst;
	l=left(i);
	r=right(i);
	if(l<=H->size&&H->data[l]>H->data[i]){
		largerst=l;
	}
	else
		largerst=i;
	if(r<=H->size&&H->data[r]>H->data[largerst]){
		largerst=r;
		//TODO
	}
	if(largerst!=i){
		swap(H,i,largerst);
		heapify(H,largerst);//TODO
	}
}
void initHeap(Heap H, ElementType data[], int n){
	int i;
	for(i=1;i<=n;i++){
		H->data[i]=data[i];
	}
	H->size=n;
	for(i=n/2;i>=1;i--){
		heapify(H,i);
	}
}
void heapSort(Heap H){
	int n=H->size;
	for(int i=H->size;i>1;i--){
		swap(H,1,i);
		H->size--;
		heapify(H,1);
	}
	H->size=n;
}
void destroyHeap(Heap H){
	if(H!=NULL){
		free(H->data);
		free(H);//TODO
	}
}
ElementType front(Heap H){
	return H->data[1];
}
int push(Heap H,ElementType x){
	if(full(H)){
		return 0;//TODO
	}
	H->size++;
	int i=H->size;
	H->data[i]=x;
	while(i>1&&H->data[parent(i)]<H->data[i]){
		swap(H,i,parent(i));
		i=parent(i);//TODO
	}
	return 1;
}
void pop(Heap H){
	H->data[1]=H->data[H->size];
	H->size--;
	heapify(H,1);
}
int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
