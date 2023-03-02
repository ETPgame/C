#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int n,i,j,sum,a;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		sum=1;
		for(j=1;j<=a;j++){
			sum*=j;
		}
		printf("%d\n",sum);
	}
} 
