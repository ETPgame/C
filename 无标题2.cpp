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

void delEdge(Graph g,VertexType x,VertexType y){
	
}
