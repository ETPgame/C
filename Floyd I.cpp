#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 200 //��󶥵���
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
	ENode *p;
	n=g->vertexNum;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
				D[i][j]=0;
			else
				D[i][j]=INT_MAX;
			P[i][j]=i;
		}
	}
	for(i=0;i<n;i++){
		p=g->vexs[i].firstEdge;
		while(p!=NULL){
			j=p->adjVertex;
			D[i][j]=p->weight;
			p=p->nextEdge;
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(D[i][k]==INT_MAX)continue;
			for(j=0;j<n;j++){
				if(i==j||D[k][j]==INT_MAX)continue;
				if(D[i][j]>D[i][k]+D[k][j]){
					D[i][j]=D[i][k]+D[k][j];
					P[i][j]=P[k][j];
				}
			}
		}
	}
}
