#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
    ElementType *array; //���ջ����
    int top;	 		//ջ��
    int capacity;  		//����
} SeqStack;

SeqStack* createStack(int capacity){
	SeqStack* S;
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->top=-1;
	S->capacity=capacity;
	S->array =(ElementType*)malloc(capacity*sizeof(ElementType));
	return S;
}
int full(SeqStack *S){
	if(S->top>=S->capacity-1){
		return 1;
	}
	else {
		return 0;
	}
}
int push(SeqStack *S,ElementType x){
	if(S->top >=S->capacity -1){
		return 0;
	} 
	else{
		S->top ++;
		S->array[S->top ] =x;
		return 1;
	}
}
int empty(SeqStack *S){
	if(S->top ==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int pop(SeqStack*S){
	if(S->top==-1){
		return 0;
	}
	else{
		S->top--;
		return 1;
	}
}
ElementType top (SeqStack *S){
	return S->array [S->top ];
}
void destroyStack(SeqStack *S){
	free(S->array );
	free(S);
}
int main()
{
    /*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
    return 0;
}


