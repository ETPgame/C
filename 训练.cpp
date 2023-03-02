#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
	ElementType *array;
	int length;
	int capacity;
}SeqList;

SeqList* createList(int capacity){
	SeqList* L=(SeqList*)malloc(sizeof(SeqList));
	L->array=(ElementType*)malloc(sizeof(ElementType)*capacity);
	L->capacity=capacity;
	L->length=0;
	return L;
}




int main(){
	SeqList *L=createList(100);
	return 0;
}

