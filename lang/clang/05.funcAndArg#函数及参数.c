//lastEdit=>2024.04.26-21:49
// 函数及参数

#include<stdio.h>
#include<string.h>

// 函数声明区域
char *genFood(int flag,char channel[20]);
char *genMeal(char *Food);
void *eatMeath(char *Meal);

int main(){
	char *channel[20];
	// 01.生成食物
	printf("%s\n",genFood(1,channel));
	return 0;
}

// 01.生成食物
char *genFood(int flag,char channel[20]){
	switch(flag){
		case 0:
			strcpy(channel,"vagetable");
			break;
		// case 1:
		// 	Food = "beef";
		// 	break;
		// default:
		// 	Food = "empty";
	}
	return channel;
}

// 02.烹饪方法
char *genMeal(char *Food){

	return NULL;
}

// 03.进食方法
void *eatMeath(char *Meal){

	return NULL;
}
