//lastEdit=>2024.04.26-20:16
// 判断与循环

#include<stdio.h>

// 虚拟bool
#define none -1
#define false 0
#define true 1

int main(){
	int flag[]={-1,0,1};
	// if判断
	printf("example01->\n\t");
	if(flag[0]==none){printf("flag[0] access!!!\n");}

	// if-else判断
	printf("example02->\n\t");
	if((flag[1]==false)==false){printf("flag[1] accecc!!!\n");}
	else{printf("flag[1] delay!!!\n");}

	// switch判断
	printf("example03->\n\t");
	switch(flag[0]){
		case -1:
			printf("flag[0] accecc!!!\n\t");
		case 0:
			printf("flag[1] accecc!!!\n\t");
			break;
		case 1:
			printf("flag[2] accecc!!!\n\t");
		default:
			printf("all access!!!\n\t");
	}
	return 0;
}