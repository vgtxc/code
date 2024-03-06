#include<stdio.h>

struct node{
    int age;
    int outAge(){
        printf("%d\n",age);
        return 0;
    };
};
 
int main(){
    struct node n01;
    n01.age = 11;
    return 0;
}