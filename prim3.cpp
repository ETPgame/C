#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //�����
	EdgeType edge[MAXVEX][MAXVEX]; //�ڽӾ���,���߱�
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
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
    */
	return 0;
}

