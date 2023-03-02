#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,temp,k;
	char zifu[100][20]={0};
	char lin[20]={0};
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		gets(zifu[i]);
	}
	for(i=1;i<=n;i++){
		k=i;
		for(j=i+1;j<=n;j++){
			temp=strcmp(zifu[k],zifu[j]);
			if(temp==1){
				k=j;
			}
		}
		if(k!=i){
			strcpy(lin,zifu[k]);
			strcpy(zifu[k],zifu[i]);
			strcpy(zifu[i],lin);
		}
		printf("%s\n",zifu[i]);	
	}
	
	return 0;
}
