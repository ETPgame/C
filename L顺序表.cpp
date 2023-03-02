#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *array;
	int length ;
	int capacity;
	
}SeqList;//����һ���ṹ�� 

SeqList* createList(int capacity){
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	L->length=0;
	L->capacity=capacity;
	L->array=(ElementType*)malloc(capacity*sizeof(ElementType));
	return L;
}
//����L˳��� 

int isEmpty(SeqList *L){
	return L->length==0; 
}
//�ж��Ƿ�Ϊ�� 

void printList(SeqList*L){
	int i;
	if(L->length!=0){
		for(i=0;i<L->length;i++){
			printf("%d ",L->array[i]);	
		} 
		printf("\n");
	}
}
//��ӡ˳��� 

int getLength(SeqList*L){
	return L->length; 
}
//����˳����� 

int insertList(SeqList*L,int i,ElementType x){
	int k;
	if(L->length>=L->capacity){
		return 0;
	}
	if(i<1||i>L->length+1){
		return 0;
	} 
	else{
		for(k=L->length-1;k>=i-1;k--){
			L->array[k+1]=L->array[k];
		}
		L->array[i-1]=x;
		L->length++;
		return 1;
	}
}
//�������� 

int find(SeqList*L,ElementType x){
	int i,j;
	j=0;
	for (i=0;i<L->length;i++){
		if(L->array[i]==x){
			j=i+1;
			return j;
		}
	}
	return -1;
}
//�������� 

int getElement(SeqList*L,int i,ElementType*p){
	if(i<1||i>L->length){
		return 0;
	}
	*p=L->array[i-1];
	return 1;
}
//��ȡ����

int delElement(SeqList*L,int i,ElementType *p){
	int k;
	if(i<1||i>L->length){
		return 0;
	} 
	*p=L->array[i-1];
	for(k=i;k<=L->length;k++){
		L->array[k-1]=L->array[k];
	}
	L->length--;
	return 1;
}
 //ɾ������ 

void delRepeatElement(SeqList*L){
	int i,j,k;
	for (i=0;i<L->length;i++){
		for(j=i+1;j<=L->length;j++){
			if(L->array[j]==L->array[i]){
				for(k=j;k<=L->length;k++){
					L->array[k]=L->array[k+1];
				}
				L->length--;
				j--;
			}
		}
	}
}
//ɾ���ظ����� 

void clearList(SeqList*L){
	L->length=0; 
}
//������� 

void mergeList(SeqList*LA,SeqList*LB,SeqList*LC){
	int i,j,k;
	i=j=k=0;
	while(i<LA->length&&j<LB->length){
		if(LA->array[i]<=LB->array[j]){
			LC->array[k++]=LA->array[i++];
		}
		else{
			LC->array[k++]=LB->array[j++];
		}
	} 
	while(i<LA->length){
		LC->array[k++]=LA->array[i++];
	}
	while(j<LB->length){
		LC->array[k++]=LB->array[j++];
	}
	LC->length=k;
}
//����ϲ� 

void destroyList(SeqList*L){
	if(L!=NULL){
		free(L->array);
		free(L);
	}
}
//���� 



