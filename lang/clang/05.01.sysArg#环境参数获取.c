//lastEdit=>2024.05.07-17:35
// 获取环境变量,命令行变量

#include<stdio.h>
#include<stdlib.h>

int main(int argn,char* argv[],char* envArg[]){
	// 命令行参数
	for(int i=0;argv[i]!=NULL;i++){
		printf("argv idx:%d\targv val:%s\n",i,argv[i]);
	}
	// 系统环境变量
	for(int i=0;envArg[i]!=NULL;i++){
		printf("envArg idx:%d\tenvArg val:%s\n",i,envArg[i]);
		system("pause");
	}
}