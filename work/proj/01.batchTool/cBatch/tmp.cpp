#include <iostream>
// #include <string>
// 父->子   pFather->pSon
// 父对象
class people{
    public:
        int fflag=11;
};
class student:public people{
    public:
        int sflag=22;
    
};
void student::out(){
    cout<<sflag<<endl;
};

int main(){
    using namespace std;
    string a = "hello word";
    cout<<a<<endl;
    return 0;
}