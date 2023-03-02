#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
	ElementType *array;
	int front;      //����λ��
	int rear;       //βָ��һ��λ��
	int length;     //����
	int capacity;   //������
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
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
	return 0;
}
