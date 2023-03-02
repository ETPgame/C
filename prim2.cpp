#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 1000 //��󶥵���
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
	ENode *firstEdge; //��һ������
} VNode;

typedef struct
{
	VNode vexs[MAXVEX];
	int vertexNum,edgeNum; //�����ͱ���
}AdjGraph,*Graph;

int locateVertex(Graph g, VertexType v){
	for(int i=0;i<g->vertexNum;i++){
		if(g->vexs[i].data==v){
			return i;
			//TODO
		}
	}
	return -1;
}
void addVertex(Graph g, VertexType v){
	int k=locateVertex(g,v);
	if(k!=-1)return ;
	int n=g->vertexNum;
	g->vexs[n].data=v;
	g->vexs[n].firstEdge=NULL;
	g->vertexNum++;
}
ENode* findEdge(Graph g, int i, int j){
	ENode *p=g->vexs[i].firstEdge;
	while(p!=NULL&&p->adjVertex!=j){
		p=p->nextEdge;
	}
	return p;
}
void addEdge(Graph g, VertexType v1, VertexType v2, int w){
	ENode *s,*t;
	int i,j;
	i=locateVertex(g,v1);
	j=locateVertex(g,v2);
	if(i==-1||j==-1)return ;
	s=findEdge(g,i,j);
	if(s!=NULL){
		if(s->weight>w){
			t=findEdge(g,j,i);
			s->weight=w;
			t->weight=w;
		}
	}
	else{
		s=(ENode*)malloc(sizeof(ENode));
		s->adjVertex=j;
		s->weight=w;
		s->nextEdge=g->vexs[i].firstEdge;
		g->vexs[i].firstEdge=s;
		t=(ENode*)malloc(sizeof(ENode));
		t->adjVertex=i;
		t->weight=w;
		t->nextEdge=g->vexs[j].firstEdge;
		g->vexs[j].firstEdge=t;
		g->edgeNum++;
	}
}

int findMin(int LowCost[],int n){
	int j;
	int min=INT_MAX;
	int k=-1;
	for(j=0;j<n;j++){
		if(LowCost[j]!=0&&min>LowCost[j]){
			min=LowCost[j];
			k=j;
		}
	}
	return k;
}
int Prim(Graph g, VertexType u, Graph t){
	int i,j,k,sum;
	int LowCost[MAXVEX];
	ENode *p;
	t->vertexNum=0;
	t->edgeNum=0;
	for(i=0;i<g->vertexNum;i++){
		LowCost[i]=INT_MAX;
	}
	k=locateVertex(g,u);
	LowCost[k]=0;
	p=g->vexs[k].firstEdge;
	while(p!=NULL){
		j=p->adjVertex;
		LowCost[j]=p->weight;
		p=p->nextEdge;
	}
	sum=0;
	for(i=1;i<g->vertexNum;i++){
		k=findMin(LowCost,g->vertexNum);
		if(k==-1){
			return -1;
		}
		sum=sum+LowCost[k];
		LowCost[k]=0;
		p=g->vexs[k].firstEdge;
		while(p!=NULL){
			j=p->adjVertex;
			if(LowCost[j]!=0&&LowCost[j]>p->weight){
				LowCost[j]=p->weight;
			}
			p=p->nextEdge;
		}
	}
	return sum;
}

int main()
{
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
	return 0;
}
