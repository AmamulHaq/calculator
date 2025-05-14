#include<iostream>
using namespace std;
int multi(float a,float b){
    return a*b;
}
int main(){
    float a=4, b=2, result;
    result=add(a,b);
    result=sub(a,b);
    result=multi(a,b);
    result=divide(a,b);
}