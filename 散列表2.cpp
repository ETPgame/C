#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;

typedef struct HashNode
{
	ElementType key;
	struct HashNode * next;
}HashNode,* List;

typedef struct
{
	int size;
	List * lists;//槽指针,所有链表均有头结点
}HashTable;

int nextPrime(int n);
HashTable * create(int size);
int hash(HashTable * h,ElementType key);
HashNode * find(HashTable * h,ElementType key);
void insert(HashTable * h,ElementType key);
HashNode * findPre(HashTable * h,ElementType key);
void del(HashTable * h,ElementType key);
void destroy(HashTable * h) ;
int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
int Prime(int n){
	if(n==2)return 1;
	if(n%2==0)return 0;
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0)return 0;
	}
	return 1;
}
int nextPrime(int n){
	if(n%2==0)n++;
	while(!Prime(n)){
		n+=2;
	}
	return n;
}
HashTable * create(int size){
	int i;
	HashTable *h=(HashTable*)malloc(sizeof(HashTable));
	h->size=nextPrime(size);
	h->lists=(List*)malloc(sizeof(List)*h->size);
	for(i=0;i<h->size;i++){
		h->lists[i]=(HashNode*)malloc(sizeof(HashNode));
		h->lists[i]->next=NULL;
	}
	return h;
}
HashNode * find(HashTable * h,ElementType key){
	HashNode*p;
	List l;
	int k=hash(h,key);
	l=h->lists[k];
	for(p=l->next;p!=NULL;p=p->next){
		if(p->key==key)return p;
	}
	return NULL;
}
void insert(HashTable * h,ElementType key){
	HashNode *Pos,*p;
	List l;
	int k;
	Pos=find(h,key);
	if(Pos!=NULL)return ;
	p=(HashNode*)malloc(sizeof(struct HashNode));
	p->key=key;
	k=hash(h,key);
	l=h->lists[k];
	p->next=l->next;
	l->next=p;
}
HashNode * findPre(HashTable * h,ElementType key){
	HashNode *p;
	List l;
	int k=hash(h,key);
	l=h->lists[k];
	for(p=l;p->next!=NULL;p=p->next){
		if(p->next->key==key)return p;
	}
	return NULL;
}
void del(HashTable * h,ElementType key){
	HashNode *pre=NULL;
	HashNode *t;
	pre=findPre(h,key);
	if(pre==NULL)return;
	t=pre->next;
	pre->next=t->next;
	free(t);
}
void destroy(HashTable * h) {
	List l,p,t;
	for(int i=0;i<h->size;i++){
		l=h->lists[i];
		p=l;
		while(p!=NULL){
			t=p->next;
			free(p);
			p=t;
		}
	}
	free(h->lists);
	free(h);
}
