#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct
{
	ElementType key; //关键数字
	int flag;        //状态标志：USED(槽已用)或EMPTY(空闲)
}Cell;

typedef struct
{
	Cell *cells;  //散列表槽指针
	int capacity; //散列表容量
	int size;     //散列表大小
}HashTable;

HashTable * create(int capacity);

int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
int nextPrime(int n);
HashTable * create(int capacity);
int hash(HashTable * h,ElementType key);
int find(HashTable * h,ElementType key);
void insert(HashTable * h,ElementType key);
void rehash(HashTable * h);
void destroy (HashTable * h);
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
HashTable * create(int capacity){
	HashTable *h=(HashTable*)malloc(sizeof(HashTable));
	int i;
	int k=nextPrime(capacity);
	h->size=0;
	h->capacity=k;
	h->cells=(Cell*)malloc(sizeof(Cell)*k);
	for(i=0;i<k;i++){
		h->cells[i].flag=EMPTY;
	}
	return h;
}
int hash(HashTable * h,ElementType key){
	return key%h->capacity;
}
int find(HashTable * h,ElementType key){
	int firstPos,curPos;
	int i=0;
	firstPos=hash(h,key);
	curPos=firstPos;
	while(1){
		if(h->cells[curPos].flag==EMPTY)break;
		if(h->cells[curPos].key==key)break;
		i++;
		curPos=(firstPos+i*i)%h->capacity;
	}
	return curPos;
}
void insert(HashTable * h,ElementType key){
	int Pos;
	Pos=find(h,key);
	if(h->cells[Pos].flag==EMPTY){
		h->size++;
		h->cells[Pos].flag=USED;
		h->cells[Pos].key=key;
		if(h->size>=h->capacity/2)rehash(h);
	}
}
void rehash(HashTable * h){
	int i,OldSize;
	Cell* OldCells;
	OldCells=h->cells;
	OldSize=h->capacity;
	int k=nextPrime(2*h->capacity);
	h->capacity=k;
	h->cells=(Cell*)malloc(sizeof(Cell)*k);
	for(i=0;i<k;i++){
		h->cells[i].flag=EMPTY;
	}
	for(i=0;i<OldSize;i++){
		if(OldCells[i].flag==USED){
			insert(h,OldCells[i].key);
		}
	}
	free(OldCells);
}
void destroy (HashTable * h){
	free(h->cells);
	free(h);
}
