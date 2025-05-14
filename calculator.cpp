#include<iostream>
using namespace std;
int add(float a, float b){
    return a+b;
}
int main(){
    float a=4, b=2; 
    int result;
    result=add(a,b);
    result=sub(a,b);
    result=multi(a,b);
    result=div(a,b);
}