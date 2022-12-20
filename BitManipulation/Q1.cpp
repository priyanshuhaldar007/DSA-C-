// checking power of 2

#include<iostream>
using namespace std;

/*
n & n-1 -> returns 0 if the number is a power of 2 and any non-zero if not
using ! operator we flip the return value
*/
bool isPowerOf2(int n){
    return n && !(n & n-1);
}

int main(){
    int n =0;
    cout<<(n & n-1)<<endl;
    cout<<isPowerOf2(n)<<endl;

    return 0;
}