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
	int visited; //�������. 1:�ѱ���  0:δ����
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
int delEdgeNum(Graph g,int i,int j){
	ENode*pre,*p,*temp;
	p=g->vexs[i].firstEdge;
	if(p!=NULL){
		if(p->adjVertex==j){
			temp=p;
			g->vexs[i].firstEdge=p->nextEdge;
			free(temp);
			return 1;
		}
		//TODO
	}
	else{
		pre=p;
		p=p->nextEdge;
		while(p!=NULL&&p->adjVertex!=j){
			pre=p;p=p->nextEdge;
		}
		if(p!=NULL){
			pre->nextEdge=p->nextEdge;
			free(p);
			return 1;
			//TODO
		}
	}
	return 0;
}
void delEdge(Graph g,VertexType x,VertexType y){
	int i,j;
	i=locateVertex(g,x);
	j=locateVertex(g,y);
	if(i==-1||j==-1||i==j)return;
	int k=delEdgeNum(g,i,j);
	delEdgeNum(g,j,i);
	if(k==1)g->vertexNum--;
}
