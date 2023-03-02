#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 200 //最大顶点数
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

void Dijkstra(Graph g, int s, int D[], int P[]);

int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
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
