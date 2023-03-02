#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
	ElementType *array; 
	int top;	 		
	int capacity;  		
} SeqStack;
SeqStack* createStack(int capacity)
{
	SeqStack * S;
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->top=-1;
	S->capacity=capacity;
	S->array=(ElementType *)malloc(capacity*sizeof(ElementType));
	return S;
}
int main()
{
	SeqStack * S;
	char str[100];
	int i;
	S=createStack(100);
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if('0'<=str[i]&&str[i]<='9')
		{
			S->top++;
			S->array[S->top]=str[i]-'0';
		}
		if(str[i]=='*')
		{
			S->array[S->top-1]=S->array[S->top]*S->array[S->top-1];
			S->top--;
		}
		else if(str[i]=='-')
		{
			S->array[S->top-1]=S->array[S->top-1]-S->array[S->top];
			S->top--;
		}
		else if(str[i]=='+')
		{
			S->array[S->top-1]=S->array[S->top]+S->array[S->top-1];
			S->top--;
		}
		else if(str[i]=='/')
		{
			S->array[S->top-1]=S->array[S->top-1]/S->array[S->top];
			S->top--;
		}
	}
	printf("%d\n",S->array[S->top]);
	return 0;
}
