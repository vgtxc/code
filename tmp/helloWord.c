#include<stdio.h>

int main(int argc,char* argv[],char* argenv[]){
	printf("hello word\n");
	for(int i=0;i<argc;i++){
		printf("argv[%d]%s\n",i,argv[i]);
	}
	return 0;
}