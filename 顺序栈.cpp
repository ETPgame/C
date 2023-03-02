#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
    ElementType *array; //存放栈数据
    int top;	 		//栈顶
    int capacity;  		//容量
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
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}


