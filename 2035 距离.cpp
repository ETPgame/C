#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c,d,i,j;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	i=sqrt(pow(a-c,2)+pow(b-d,2));
	printf("%.2lf\n",i);
	return 0;
}
