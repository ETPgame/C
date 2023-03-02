#include<stdio.h>

int main(){
	int n,i;
	scanf("%d",&n);
	int a[n+1];
	int b[n]={0};
	int count=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++){
		if(a[i]>a[i+1])
			b[i]=a[i]-a[i+1];
		else
			b[i]=a[i+1]-a[i];
	}
	for(i=1;i<=n-1;i++){
		if(b[i]==0){
			count++;
			break;
		}
	}
	if(count!=0)
		printf("%d Boring games\n",n);
	else
		printf("%d Fun games\n",n);
}
