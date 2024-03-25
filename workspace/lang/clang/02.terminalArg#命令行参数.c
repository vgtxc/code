/*
获取命令行(终端)参数:
	格式:
		//---->argn:输入参数个数
		//---->argv:输入参数的具体值
		//---->envp:系统环境变量
		<dataType> main(int argc,char *argv[],char *envp[])
		{
			//main函数
		}
*/

#include <stdio.h>

//生成main.exe可执行文件后输入
//main.exe aa bb cc dd ee ff
//---->argn:输入参数个数
//---->argv:输入参数的具体值
//---->envp:系统环境变量
void main(int argn,char *argv[],char *envp[])
{
	printf("The number of Terminal_arg:%d\n\n",argn);
	printf("The value of Terminal_arg:\n");
	int i;
	for(i=0;i<argn;i++)
	{
		printf("\t%s\n", argv[i]);
	}
}