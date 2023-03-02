#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 200 //��󶥵���
typedef char VertexType;

typedef struct ENode
{
	int adjVertex;  //�ñ���ָ�Ķ�����
	int weight;     //��Ȩ
	struct ENode *nextEdge;  //��һ����
} ENode;

typedef struct VNode
{
	VertexType data;   //������Ϣ
	int visited; //�������. 1:�ѱ���  0:δ����
	ENode *firstEdge; //��һ������
} VNode;

typedef struct
{
	VNode vexs[MAXVEX];
	int vertexNum,edgeNum; //�����ͱ���
}AdjGraph,*Graph;

void Dijkstra(Graph g, int s, int D[], int P[]);

int main()
{
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
	return 0;
}

int findMin(Graph g,int D[],int final[]){
	int i,min,k;
	k=-1;
	min=INT_MAX;
	for(i=0;i<g->vertexNum;i++){
		if(final[i]!=-1&&min>D[i]){
			min=D[i];
			k=i;
		}
	}
	return k;
}
void Dijkstra(Graph g, int s, int D[], int P[]){
	int i,k;
	int final[MAXVEX];
	ENode *p;
	for(i=0;i<g->vertexNum;i++){
		D[i]=INT_MAX;
		final[i]=0;
	}
	p=g->vexs[s].firstEdge;
	while(p!=NULL){
		i=p->adjVertex;
		D[i]=p->weight;
		P[i]=s;
		p=p->nextEdge;
		final[s]=1;
		D[s]=0;
	}
	while(1){
		k=findMin(g,D,final);
		if(k==-1)return ;
		final[k]=1;
		p=g->vexs[k].firstEdge;
		while(p!=NULL){
			i=p->adjVertex;
			if(final[i]!=1&&D[i]>D[k]+p->weight){
				D[i]=D[k]+p->weight;
				P[i]=k;
			}
			p=p->nextEdge;
		}
	}
}
