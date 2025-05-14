#include<iostream>
using namespace std;

float add(float a, float b){
    return a+b;}
float sub(float a,float b){
    return a-b;}
float multi(float a,float b){
    return a*b;}
float div(float a,float b){
    return a/b;
}
int main(){
    float a, b, result;

    cout<<"Enter any two number: "<<endl;
    cin>>a>>b;
    cout<<"add: "<<add(a,b)<<endl;
    cout<<"sub: "<<sub(a,b)<<endl;
    cout<<"multi: "<<multi(a,b)<<endl;
    cout<<"div: "<<div(a,b)<<endl;
    

    return 0;
}