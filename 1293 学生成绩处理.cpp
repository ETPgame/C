#include<stdio.h>
struct stu{
	double a,b,c,sum;
}s[5];
int main(){
	int i,j,n;
	double m;
	for(i=0;i<5;i++){
		scanf("%lf %lf %lf",&s[i].a ,&s[i].b ,&s[i].c );
		s[i].sum =s[i].a +s[i].b+s[i].c;
	}
	for(i=0;i<5;i++){
		n=i;
		for(j=i+1;j<5;j++){
			if(s[n].sum <s[j].sum ){
				n=j;
			}
		}
		if(n!=i){
			m=s[i].a ;
			s[i].a =s[n].a ;
			s[n].a =m;
			m=s[i].b ;
			s[i].b=s[n].b ;
			s[n].b =m;
			m=s[i].c ;
			s[i].c=s[n].c ;
			s[n].c =m;
			m=s[i].sum ;
			s[i].sum =s[n].sum;
			s[n].sum =m;
		}
		printf("%.1lf %.1lf %.1lf %.1lf\n",s[i].a ,s[i].b ,s[i].c ,s[i].sum ); 
	}
}
