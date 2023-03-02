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

void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]);

int main()
{
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ�� 
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
