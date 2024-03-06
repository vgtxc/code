#include<stdio.h>

//	总人数
#define totalNum 5

int main(){
	//	分数
	int arr[totalNum] = {1,2,3,4,5};
	//	最大值，最小值
	int minvalu=arr[0],maxvalu=arr[0];
	//	总分数
	int totalvalu = 0;
	//	寻找最大，最小分数
	for(int i=0;i<totalNum;i++){
		if(arr[i]<minvalu){minvalu = arr[i];}
		if(arr[i]>maxvalu){maxvalu = arr[i];}
		totalvalu += arr[i];
	}
	//	减去最低最高分求平均
	totalvalu -= (minvalu+maxvalu);
	float rst = totalvalu/(totalNum-2);
	printf("result\t->%f\n",rst);
	return 0;
}