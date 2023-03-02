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

void delEdge(Graph g,VertexType x,VertexType y){
	
}
