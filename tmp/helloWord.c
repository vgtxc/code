#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[],char* argenv[]){
	printf("hello word\n");
	for(int i=0;i<argc;i++){
		printf("argv[%d]%s\n",i,argv[i]);
	}
	system("pause");
	return 0;
}
