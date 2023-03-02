#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
	int vertexNum,edgeNum;
}MGraph,*Graph;

int locateVertex(Graph g,VertexType v){
	for(int i=0;i<g->vertexNum;i++){
		if(g->vexs[i]==v){
			return i;
			//TODO
		}
	}
	return -1;
}
int findMin(int lowCost[],int n){
	int j;int k=-1;
	int min=INT_MAX;
	for(j=0;j<n;j++){
		if(lowCost[j]!=0&&min>lowCost[j]){
			min=lowCost[j];
			k=j;
		}
	}
	return k;
}
int Prim(Graph g, VertexType u){
	int i,j,k,sum;
	int lowCost[MAXVEX];
	int parent[MAXVEX];
	k=locateVertex(g,u);
	int n=g->vertexNum;
	for(i=0;i<n;i++){
		lowCost[i]=g->edge[k][i];
		parent[i]=k;
	}
	lowCost[k]=0;
	parent[k]=-1;
	sum=0;
	for(i=1;i<n;i++){
		k=findMin(lowCost,n);
		if(k==-1)return -1;
		sum+=lowCost[k];
		lowCost[k]=0;
		for(j=0;j<n;j++){
			if(lowCost[j]!=0&&lowCost[j]>g->edge[k][j]){
				lowCost[j]=g->edge[k][j];
				parent[j]=k;
			}
		}
	}
	return sum;
}
int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}

