#define _CRT_SECURE_NO_WARNINGS     //防止报错
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>

typedef int ElementType;
typedef  struct  Node{
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
}BSTNode, *BSTree;
BSTree newNode(ElementType x){
	BSTree p=(BSTree)malloc(sizeof(BSTNode));
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
BSTree insert(BSTree bst, ElementType x){
	if(bst==NULL){
		bst=newNode(x);
	}
	else if(x<bst->data){
		bst->lchild=insert(bst->lchild,x);
	}
	else if(x>bst->data){
		bst->rchild=insert(bst->rchild,x);
	}
	return bst;
}
BSTNode* find(BSTree bst,ElementType x){
	BSTree p;
	p=bst;
	while(p!=NULL&&x!=p->data){
		if(x<p->data){
			p=p->lchild;
		}
		else if(x>p->data){
			p=p->rchild;
		}
	}
	return p;
}
BSTree destroyBSTree(BSTree bst){
	if(bst==NULL){
		return NULL;
	}
	destroyBSTree(bst->lchild);
	destroyBSTree(bst->rchild);
	free(bst);
}
int main() 
{   
	//setlocale(LC_CTYPE, "");
	SetConsoleOutputCP(CP_UTF8);    //中文输出不乱码
	clock_t start = clock();
	FILE* fIn = fopen("in.txt", "r"), * fOut = fopen("out.txt", "w");
	int str;  //根据需要选择类型，比如int str;
	BSTree bst=NULL;
	int cout=0;
	if (fIn == NULL || fOut == NULL) {
		printf("Failed!\n");
		return 1;
	}
	
	while (!feof(fIn)) {
		fscanf(fIn, "%s", str);  //从文件中读数据，使用方式和scanf一样
		if(find(bst,str)==NULL){
			
		}
		printf("%s \n", str);
		fprintf(fOut, "%s \n", str);  //写数据到文件，使用方式和printf一样
	}
	fclose(fIn);
	fclose(fOut);
	
	printf("\nTime= %.4f ms\n", (double)clock() - start);
	return 0;
}
