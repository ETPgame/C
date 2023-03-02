#include<stdio.h>

int main(){
	int i,j,m,n;
	double max;
	double shu[50][50];
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++){
		max=0; 
		for(j=1;j<=n;j++){
			scanf("%lf",&shu[i][j]);
			if(shu[i][j]>max){
				max=shu[i][j];
			}
		}
		for(j=1;j<=n;j++){
			shu[i][j]/=max;
			printf("%.2lf",shu[i][j]);
			if(j<n)printf(" ");
		}
		printf("\n");
	}
	return 0;
 } 
