//lastEdit=>2024.05.09-15:56
// 系统命令调用函数

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argn,char *argv[],char *envArg[]){
	// 创建cmd命令字符串内存,并初始化内存
	char cmd[30]={};
	// printf("cmd is:%s\n", cmd);
	for(int i=0;argv[i]!=NULL;i++){
		// 生成cmd命令
		strcat(cmd,"echo \t");
		strcat(cmd,argv[i]);
		// 打印生成的cmd命令
		printf("cmd is:%s\n", cmd);
		// 系统调用命令
		system(cmd);
		// 重置字符串内存
		strcpy(cmd,"");
	}
	return 1;
}