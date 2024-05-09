//lastEdit=>2024.05.07-17:01
//lastEdit=>2024.05.06-21:20
//lastEdit=>2024.04.26-21:49
// 函数及参数

#include<stdio.h>
#include<string.h>
#include<malloc.h>

// 函数声明区域
char *genFood(int flag,char channel[20]);
char *cookMet(char *Food);
char *eatMeal(char *Meal);

int main(){
	// 通道变量
	char *midArg=(char *)malloc(30);
	int flag = 1;
	printf("Flag is:%d\n",flag);
	// 01.生成食物
	printf("01.Food is:%s\n",genFood(flag,midArg));
	// 02.烹饪方法
	printf("02.Meal is:%s\n",cookMet(midArg));
	// 03.判断是否是饮食
	printf("03.delicious?:%s\n",eatMeal(midArg));
	return 0;
}

// 01.生成食物
char *genFood(int flag,char *midArg){
	switch(flag){
		case 0:
			strcpy(midArg,"tomato");
			break;
		case 1:
			strcpy(midArg,"beef");
			break;
		case 2:
			strcpy(midArg,"fish");
			break;
		default:
			strcpy(midArg,"empty");
	}
	return midArg;
}

// 02.烹饪方法
char *cookMet(char *Food){
	// 没有食物返回空
	if(strcmp(Food,"empty")==0){strcpy(Food,"empty");}
	if(strcmp(Food,"tomato")==0){strcpy(Food,"cook tomato");}
	if(strcmp(Food,"beef")==0){strcpy(Food,"cook beef");}
	if(strcmp(Food,"fish")==0){strcpy(Food,"cook fish");}
	// printf("Food is:%s\tstrcmp:%d\n",Food,strcmp(Food,"beef"));
	return Food;
}

// 03.进食方法
char *eatMeal(char *Meal){
	// 没有食物返回空
	if(strcmp(Meal,"empty")==0){strcpy(Meal,"Just A Sh***");}
	else{strcpy(Meal,"very good");}
	return Meal;
}
