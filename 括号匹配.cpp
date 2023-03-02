#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct
{
	char *array; 
	int top;	 		
	int capacity;  		
} SeqStack;
SeqStack* createStack(int capacity)
{
	SeqStack * S;
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->top=-1;
	S->capacity=capacity;
	S->array=(char *)malloc(capacity*sizeof(char));
	return S;
}
int main()
{
	SeqStack * S;
	char str[1000];
	int i;
	S=createStack(1000);
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
		{
			S->top++;
			S->array[S->top]=str[i];
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			if(S->top==-1)
			{
				printf("no\n");
				return 0;
			}
			else
			{
				if(str[i]-S->array[S->top]==1||str[i]-S->array[S->top]==2)
				{
					S->top--;
				}
			}
		}
	}
	if(S->top!=-1)
	{
		printf("no\n");
	}
	else
	{
		printf("yes\n");
	}
	return 0;
}


