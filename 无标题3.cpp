#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 1000 //最大顶点数
typedef char VertexType;

typedef struct ENode
{
	int adjVertex;  //该边所指的顶点编号
	int weight;     //边权
	struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode
{
	VertexType data;   //顶点信息
	int visited; //遍历标记. 1:已遍历  0:未遍历
	ENode *firstEdge; //第一条出边
} VNode;
typedef struct
{
	VNode vexs[MAXVEX];
	int vertexNum,edgeNum; //点数和边数
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
