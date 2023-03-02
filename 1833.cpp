#include<stdio.h>
#include<string.h>
struct stu{
	char id[20],name[20],sex;
	int year,month,day;
	double x,y,z;
}s; 
int main(){
	int i,a,b;
	double average,sum;
	char pro[20]={0},c;
	while(1){
		scanf("%s",&pro);
		a=!strcmp(pro,"Quit");
		b=!strcmp(pro,"Exit");
		if(!a&&!b){
			scanf("%s %s %c %d %d %d %lf %lf %lf",&s.id,&s.name ,&s.sex ,&s.year ,&s.month ,&s.day ,&s.x ,&s.y ,&s.z );	
			sum=s.x +s.y +s.z ;
			average=sum/3;
			printf("Insert:\n"); 
			printf("%s %s %c %d %d %d %.1lf %.1lf %.1lf %.1lf %.1lf\n",s.id ,s.name ,s.sex ,s.year ,s.month ,s.day ,s.x ,s.y,s.z ,average,sum);	
		}	
		else{
			printf("Good bye!\n");
			break;
		}
	}
	return 0;
}
