#include<iostream>
using namespace std;

bool isEven(int n){
    return ((n & 1)!= 1);
}

int main(){
    cout<<isEven(5);
    return 0;
}