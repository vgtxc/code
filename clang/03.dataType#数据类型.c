//lastEdit=>2024.04.26-20:54
//lastEdit=>2024.04.24-21:42
// 数据类型

#include<stdio.h>

int main(){
	// 01.数值
	// 01.01.整数数值
	short dt_short=10;
	int dt_int=10;
	long int dt_longInt=10;
	long long int dt_longLongInt=10;
	// 01.02.浮点数值
	float dt_float=3.14;
	double dt_double=3.14;
	long double dt_longDouble=3.14;
	// 01.03.无符号
	unsigned short dt_unsShort=10;
	unsigned int dt_unsInt=10;
	unsigned long int dt_unsLongInt=10;
	unsigned long long int dt_unsLLInt=10;
	// unsigned float dt_unsFloat=3.14;
	// unsigned double dt_unsDouble=3.14;
	// unsigned long double dt_unsLDouble=3.14;

	// 02.字符
	// 01.01.单字符
	char dt_char='x';
	// 01.02.字符串
	char dt_listStr[]={"hello word"};
	char *dt_pointStr="hello word";
	// 01.03.字符串数组
	char *dt_charlistStr[]={"hello","word"};

	// 03.数组
	// 03.01.数值数组
	int dt_intList[]= {0,1,2,3,4,5};
	float dt_floatList[]= {0.1, 0.2, 0.3, 0.4, 0.5};
	// 03.02.字符数组-字符串
	char dt_str[] = {"hello word"};

	// 04.指针
	int *dt_intPoint=NULL;
	dt_intPoint = dt_intList;
	char *dt_charPoint=NULL;
	dt_charPoint = dt_str;

	// 05.结构体
	struct human{
		char *eye;
		char *mouse;
	};
	struct human dt_Tony={"big","small"};
	struct human *dt_TonyPoint = &dt_Tony;
	printf("Tony eye:%s;\tTony mouse:%s;\n", dt_Tony.eye, dt_TonyPoint->mouse);

	enum color{
		red,
		green,
		blue
	};
	enum color dt_shirt = green;
	printf("dt_shirt is green?->%d\n",dt_shirt==green);

	// 其它数据类型
	// 二维数组
	char dt_strList[][10] = {"hello","word"};
	// 三维数组
	char dt_strdict[][2][10] = {{"key01","word01"},{"key02","word02"},{"key...","word..."}};
	// 二重指针
	char **dt_2deepPoint = &dt_charPoint;
	// 三重指针
	char ***dt_3deepPoint = &dt_2deepPoint;
	// 指针数组
	char dt_tmp[][10] = {"hello","word"};
	char (*dt_pointList)[10] = NULL;
	dt_pointList = dt_tmp;
	printf("dt_pointList:%s\n",dt_pointList[0]);
	// 数组指针
	char dt_tmp01[] = "hello word";
	char *dt_listPoint = NULL;
	dt_listPoint = dt_tmp01;
	printf("dt_listPoint:%s\n",dt_listPoint);

	return 0;
}