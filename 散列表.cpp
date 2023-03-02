#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct
{
	ElementType key; //�ؼ�����
	int flag;        //״̬��־��USED(������)��EMPTY(����)
}Cell;

typedef struct
{
	Cell *cells;  //ɢ�б��ָ��
	int capacity; //ɢ�б�����
	int size;     //ɢ�б��С
}HashTable;

HashTable * create(int capacity);

int main()
{
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
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
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
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
