#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct
{
	VertexType vexs[MAXVEX]; //�����
	EdgeType edge[MAXVEX][MAXVEX]; //�ڽӾ���,���߱�
	int vertexNum,edgeNum;
} MGraph,*Graph;

void Dijkstra(Graph g, int s, int D[], int P[]);

int main()
{
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
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
	for(i=0;i<g->vertexNum;i++){
		D[i]=g->edge[s][i];
		if(D[i]<INT_MAX){
			P[i]=s;
		}
		final[i]=0;
	}
	final[s]=1;
	D[s]=0;
	while(1){
		k=findMin(g,D,final);
		if(k==-1)return ;
		final[k]=1;
		for(i=0;i<g->vertexNum;i++){
			if(g->edge[k][i]==INT_MAX||final[i]){
				continue;
			}
			if(D[i]>D[k]+g->edge[k][i]){
				D[i]=D[k]+g->edge[k][i];
				P[i]=k;
			}
		}
	}
}
