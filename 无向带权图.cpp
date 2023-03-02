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

Graph createGraph()
{
	Graph g=(Graph)malloc(sizeof(AdjGraph));
	g->edgeNum=0;
	g->vertexNum=0;
	return g;
}
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
	g->vertexNum++;g->vexs[n].visited=0;
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
int degree(Graph g, VertexType v){
	int k=locateVertex(g,v);
	ENode*p=g->vexs[k].firstEdge;
	int n=0;
	while(p!=NULL){
		p=p->nextEdge;
		n++;
	}
	return n;
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
void delVertex(Graph g, VertexType v){
	int k,j;
	ENode *p;
	k=locateVertex(g,v);
	if(k==-1)return ;
	p=g->vexs[k].firstEdge;
	while(p!=NULL){
		j=p->adjVertex;
		p=p->nextEdge;
		delEdge(g,v,g->vexs[j].data);
		//TODO
	}
	g->vexs[k]=g->vexs[g->vertexNum-1];
	for(int i=0;i<g->vertexNum;i++){
		for(p=g->vexs[i].firstEdge;p!=NULL;p=p->nextEdge){
			if(p->adjVertex==g->vertexNum-1){
				p->adjVertex=k;
				//TODO
			}
		}
	}
	g->vertexNum--;
}
void DFS(Graph g, int i){
	int k;
	g->vexs[i].visited=1;
	ENode*p=NULL;
	for(p=g->vexs[i].firstEdge;p!=NULL;p=p->nextEdge){
		k=p->adjVertex;
		if(g->vexs[k].visited==0)DFS(g,k);
	}
}
void BFS(Graph g, int i){
	int v,w;
	ENode *p;
	queue<int> q;
	g->vexs[i].visited=1;
	q.push(i);
	while(!q.empty()){
		v=q.front();
		q.pop();
		p=g->vexs[v].firstEdge;
		while(p!=NULL){
			w=p->adjVertex;
			if(g->vexs[w].visited==0){
				g->vexs[w].visited=1;
				q.push(w);
			}
			p=p->nextEdge;
		}
	}
}
void destroyGraph(Graph g){
	ENode *p,*post;
	for(int i=0;i<g->vertexNum;i++){
		p=g->vexs[i].firstEdge;
		while(p!=NULL){
			post=p->nextEdge;
			free(p);
			p=post;
		}
	}
	free(g);
}
int connectedComps(Graph g){
	int n=0;
	for(int i=0;i<g->vertexNum;i++){
		if(g->vexs[i].visited==0){
			DFS(g,i);
			n++;
		}
	}
	return n;
}
int connect(Graph g, VertexType x, VertexType y){
	int i,j;
	i=locateVertex(g,x);
	j=locateVertex(g,y);
	DFS(g,i);
	return g->vexs[j].visited;
}
int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
