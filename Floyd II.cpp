#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
	int vertexNum,edgeNum;
} MGraph,*Graph;

void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]);

int main()
{
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
	return 0;
}
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]){
	int i,j,k,n;
	n=g->vertexNum;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				D[i][j]=0;
			else
				D[i][j]=g->edge[i][j];
			P[i][j]=j;
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(D[i][k]==INT_MAX){
				continue;
			}
			for(j=0;j<n;j++){
				if(i==j||D[k][j]==INT_MAX){
					continue;
				}
				if(D[i][j]>D[i][k]+D[k][j]){
					D[i][j]=D[i][k]+D[k][j];
					P[i][j]=P[k][j];
				}
			}
		}
	}
}
