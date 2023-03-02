#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
	ElementType *array;
	int front;      //队首位置
	int rear;       //尾指下一个位置
	int length;     //长度
	int capacity;   //总容量
}SeqQueue;

SeqQueue* createQueue(int capacity){
	SeqQueue *Q;
	Q=(SeqQueue *) malloc (sizeof(SeqQueue));
	Q->capacity =capacity;
	Q->front =Q->rear =0;
	Q->length =0;
	Q->array =(ElementType*)malloc(sizeof(ElementType)*capacity);
	return Q;
}
int full(SeqQueue *Q)
{
	if(Q->capacity <=Q->length ){
		return 1;
	}
	return 0;
}
int push(SeqQueue *Q, ElementType x){
	if(full(Q) ){
		return 0;
	}
	else{
		Q->array [Q->rear ]=x;
		Q->rear =(Q->rear +1)%Q->capacity ;
		Q->length ++;
		return 1;		
	}
}
int empty(SeqQueue *Q){
	if(Q->front ==Q->rear ){
		return 1;
	}
	return 0;
}
ElementType front(SeqQueue *Q){
	return Q->array [Q->front ];
}
void clearQueue(SeqQueue *Q){
	Q->front =0;
	Q->rear =0;
	Q->length =0;
}
void destroyQueue(SeqQueue *Q){
	free(Q->array );
	free(Q);
}

int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
