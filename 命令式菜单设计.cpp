#include<bits/stdc++.h>
using namespace std;
#define M 30
int main(){
	char cmd[M];
	while(1){
		scanf("%s",cmd);
		switch(cmd[0]){
			case 'I':
				printf("Insert:\n");
				break;
			case 'L':
				printf("List:\n");
				break;
			case 'F':
				printf("Find:\n");
				break; 
			case 'C':
				printf("Change:\n");
				break;
			case 'D':
				printf("Delete:\n");
				break;
			case 'Q':
			case 'E':
				printf("Good bye!\n");
				exit(0);
		}
	}
	return 0;
}

