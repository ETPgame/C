#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100 /*最大顶点数*/
typedef char VertexType;

struct AOENetworkStruct;
typedef struct AOENetworkStruct *AOENetwork;

typedef struct ENode
{
	int adjVertex;  //边的终点编号
	int weight;     //边权
	int earliest;   //活动最早开始时间
	int latest;     //活动最晚开始时间
	struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode
{
	VertexType data;    //顶点信息/
	int inDegree;       //入度/
	int earliest;       //事件最早发生时间/
	int latest;         //事件最晚发生时间
	ENode *firstEdge; //第一条出边
} VNode;

struct AOENetworkStruct
{
	VNode vexs[MAXVEX];    //点表
	int vertexNum, edgeNum; //顶点数和弧数
};

AOENetwork createGraph();
int locateVertex(AOENetwork g, VertexType v);
void addVertex(AOENetwork g, VertexType v);
ENode* findEdge(AOENetwork g, int i, int j);
int TopSort(AOENetwork g);
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w);
void event(AOENetwork g);
int active(AOENetwork g);
int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
AOENetwork createGraph(){
	AOENetwork g=(AOENetwork)malloc(sizeof(AOENetworkStruct));
	g->edgeNum=0;
	g->vertexNum=0;
	return g;
}

int locateVertex(AOENetwork g, VertexType v){
	for(int i=0;i<g->vertexNum;i++){
		if(g->vexs[i].data==v)
			return i;
	}
	return -1;
}
void addVertex(AOENetwork g, VertexType v){
	int k;
	k=locateVertex(g,v);
	if(k!=-1||k>=g->vertexNum)return;
	g->vexs[g->vertexNum].data=v;
	g->vertexNum++;
}
ENode* findEdge(AOENetwork g, int i, int j){
	ENode *p=g->vexs[i].firstEdge;
	while(p!=NULL&&p->adjVertex!=j){
		p=p->nextEdge;
	}
	return p;
}
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w){
	int m,n;
	ENode *s;
	m=locateVertex(g,v1);
	n=locateVertex(g,v2);
	if(m==-1||n==-1)return;
	ENode *p=findEdge(g,m,n);
	if(p!=NULL){
		if(p->weight>w){
			p->weight=w;
		}
	}
	else{
		s=(ENode*)malloc(sizeof(ENode));
		s->nextEdge=g->vexs[m].firstEdge;
		g->vexs[m].firstEdge=s;
		s->weight=w;
		s->adjVertex=n;
		g->edgeNum++;
		g->vexs[n].inDegree++;
	}
}
int TopSort(AOENetwork g){
	int cnt=0;
	int i,x,y;
	ENode *p=NULL;
	stack<int> in;
	for(i=0;i<g->vertexNum;i++){
		g->vexs[i].earliest=0;
		if(g->vexs[i].inDegree==0)
			in.push(i);
	}
	while(!in.empty()){
		x=in.top();
		in.pop();
		cnt++;
		for(p=g->vexs[x].firstEdge;p!=NULL;p=p->nextEdge){
			y=p->adjVertex;
			g->vexs[y].inDegree--;
			if(g->vexs[y].inDegree==0)
				in.push(y);
			if(g->vexs[y].earliest<g->vexs[x].earliest+p->weight)
				g->vexs[y].earliest=g->vexs[x].earliest+p->weight;
		}
	}
	if(cnt<g->vertexNum)
		return 0;
	return 1;
}
void event(AOENetwork g){
	int i,x,y,k;
	stack<int> out;
	int cnt=0;
	ENode *p=NULL;
	stack<int> in;
	for(i=0;i<g->vertexNum;i++){
		g->vexs[i].earliest=0;
		if(g->vexs[i].inDegree==0)
			in.push(i);
	}
	while(!in.empty()){
		x=in.top();
		in.pop();
		cnt++;
		out.push(x);
		for(p=g->vexs[x].firstEdge;p!=NULL;p=p->nextEdge){
			y=p->adjVertex;
			g->vexs[y].inDegree--;
			if(g->vexs[y].inDegree==0)
				in.push(y);
			if(g->vexs[y].earliest<g->vexs[x].earliest+p->weight)
				g->vexs[y].earliest=g->vexs[x].earliest+p->weight;
		}
	}
	if(cnt<g->vertexNum){
		k=0;
	}
	else{
		k=1;
	}
	if(!k)return;
	for(i=0;i<g->vertexNum;i++){
		g->vexs[i].latest=g->vexs[g->vertexNum-1].earliest;
	}
	while(!out.empty()){
		x=out.top();
		out.pop();
		for(p=g->vexs[x].firstEdge;p!=NULL;p=p->nextEdge){
			y=p->adjVertex;
			if(g->vexs[x].latest>g->vexs[y].latest-p->weight)
				g->vexs[x].latest=g->vexs[y].latest-p->weight;
		}
	}
}
int active(AOENetwork g){
	int i,x,y;
	ENode *p;
	int cnt=0;
	for(i=0;i<g->vertexNum;i++){
		for(p=g->vexs[i].firstEdge;p!=NULL;p=p->nextEdge){
			y=p->adjVertex;
			p->earliest=g->vexs[x].earliest;
			p->latest=g->vexs[y].latest-p->weight;
			if(p->earliest==p->latest)cnt++;
		}
	}
	return cnt;
}
