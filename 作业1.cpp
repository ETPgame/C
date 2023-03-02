#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

unsigned short func1(unsigned short si){
	return (si*256);
}
short func2(unsigned short si){
	return(si/256);
}
short func3(unsigned short si){
	short x=((short)si*256);
	return x/256;
}
short func4(unsigned short si){
	unsigned short x=(si*256);
	return (short)(x/256);
}

int main()
{
	int c[4]={0};
	int a[5]={127,128,255,256,65535};
	for(int i=0;i<5;i++){
		c[0]=func1(a[i]);
		c[1]=func2(a[i]);
		c[2]=func3(a[i]);
		c[3]=func4(a[i]);
		for(int k=0;k<=3;k++){
			printf("%d ",c[k]);
		}
		printf("\n");
	}
}
