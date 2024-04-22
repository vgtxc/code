#include<stdlib.h>
#include<iostream>
#include<string>

#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
    Mat img=imread("./img/0.git");
    imshow("cvUI",img);
    printf("hello word\n");
    return 0;
}