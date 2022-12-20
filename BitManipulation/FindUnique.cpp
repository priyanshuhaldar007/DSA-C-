/*
XOR operator truth table
A   B   A^B
------------
0   0   0
0   1   1
1   0   1
1   1   0

conclusion: 
a^1 = ~a
a^0 = a
a^a = 0
*/

#include<iostream>
using namespace std;

int ans(int arr[], int s){
    int unique =0;
    for(int i=0;i<s;i++){
        unique^=arr[i];
    }
    return unique;
}

int main(){
    int arr[] = {2,3,3,4,2,6,4};
    int s = sizeof(arr)/sizeof(arr[0]);
    cout<<ans(arr,s);
}