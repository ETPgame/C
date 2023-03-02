#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
	int vertexNum,edgeNum;
	int visited[MAXVEX];//遍历标记. 1:已遍历  0:未遍历
}MGraph,*Graph;

Graph createGraph()
{
	Graph g=(Graph)malloc(sizeof(MGraph));
	g->edgeNum=0;
	g->vertexNum=0;
	return g;
}
int locateVertex(Graph g,VertexType v){
	for(int i=0;i<g->vertexNum;i++){
		if(g->vexs[i]==v){
			return i;
			//TODO
		}
	}
	return -1;
}
void addVertex(Graph g,VertexType v){
	int k;
	k=locateVertex(g,v);
	if(k!=-1){
		return ;
		//TODO
	}
	k=g->vertexNum;
	g->vexs[g->vertexNum]=v;
	g->vertexNum++;
	for(int i=0;i<g->vertexNum;i++){
		g->edge[k][i]=0;
		g->edge[i][k]=0;
	}
}
void addEdge(Graph g, VertexType x, VertexType y){
	int j,k;
	j=locateVertex(g,x);
	k=locateVertex(g,y);
	if(j==-1||k==-1)return ;
	if(g->edge[j][k]==1)return ;
	g->edge[j][k]=1;
	g->edge[k][j]=1;
	g->edgeNum++;
}
void delEdge(Graph g,VertexType x,VertexType y)
{
	int j,k;
	j=locateVertex(g,x);
	k=locateVertex(g,y);
	if(j==-1||k==-1)return ;
	if(g->edge[j][k]==0)return ;
	g->edge[j][k]=0;
	g->edge[k][j]=0;
	g->edgeNum--;
}
void delVertex(Graph g,VertexType v){
	int j;
	j=locateVertex(g,v);
	if(j==-1)return;
	int n=g->vertexNum-1;
	g->vexs[j]=g->vexs[n];
	for(int i=0;i<g->vertexNum;i++){
		if(g->edge[i][j]==1){
			g->edgeNum--;
		}
	}
	for(int i=0;i<g->vertexNum;i++){
		g->edge[i][j]=g->edge[i][n];
		g->edge[j][i]=g->edge[n][i];
	}
	g->vertexNum--;
}
int degree(Graph g,VertexType v){
	int k=locateVertex(g,v),n=0;
	if(k==-1)return 0;
	for(int i=0;i<g->vertexNum;i++){
		if(g->edge[i][k]==1){
			n++;
		}
	}
	return n;
}
void DFS(Graph g, int i){//
	for(int j=0;j<g->vertexNum;j++){
		if(g->edge[i][j]==1&&g->visited[j]==0){
			g->visited[j]=1;
			DFS(g,j);
			//TODO
		}
	}
}
void BFS(Graph g, int i){//
	queue<int> q;
	g->visited[i]=1;
	q.push(i);
	int n;
	while(!q.empty()){
		n=q.front();
		q.pop();
		for(int j=0;j<g->vertexNum;j++){
			if(g->edge[j][n]==1){
				if(g->visited[j]==0){
					g->visited[j]=1;
					q.push(j);
				}
			}
		}
	}
}
void destroyGraph(Graph g){
	free(g);
}
int distance(Graph g,VertexType v, VertexType u){
	int a,b;
	a=locateVertex(g,v);
	b=locateVertex(g,u);
	if(a==-1||b==-1)return 0;
	queue<int> q;
	int i,j;
	for(int i=0;i<g->vertexNum;i++){
		g->visited[i]=-1;
	}
	g->visited[a]=0;
	q.push(a);
	while(!q.empty()){
		i=q.front();
		q.pop();
		for(j=0;j<g->vertexNum;j++){
			if(g->edge[i][j]==1&&g->visited[j]==-1){
			g->visited[j]=g->visited[i]+1;
			q.push(j);
			}
		}
	}
	if(g->visited[b]==-1)return 0;
	return g->visited[b];
}
int connect(Graph g, VertexType v, VertexType u){
	int a,b;
	a=locateVertex(g,v);
	b=locateVertex(g,u);
	DFS(g,a);
	return g->visited[b];
}
int connectedComps(Graph g){
	int n=0;
	for(int i=0;i<g->vertexNum;i++){
		if(g->visited[i]==0){
			DFS(g,i);
			n++;
		}
	}
	return n;
}

int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
