/*
    摘苹果
*/
#include<stdio.h>

int main(){
    int appleHig[10]={0};   // 苹果离地高度
    int peopelHig = 0;  // 人伸手最大高度
    int chartHig = 30;  // 板凳高度
    int pickNum = 0;
    // 获取输入的苹果高度
    printf("apple hig:\n\t");
    for(int i=0;i<10;i++){
        scanf("%d_",&appleHig[i]);
    }
    // 统计能够摘到的苹果个数
    printf("people hig:\n\t");
    scanf("%d",&peopelHig);
    for(int i=0;i<10;i++){
        if(appleHig[i]<=(peopelHig+chartHig)){pickNum+=1;}
    }
    // 打印结果
    printf("can pick num:\n\t%d\n",pickNum);
    return 0;
}