/*
6
15478 8452 8232 874 985 4512

check divisibility by 11

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num=0;
    cin>>n;
    int arr[n];
    int limit = n/2;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        
        if(i<limit){
            int lenOfNums = log10(arr[i]);
            while(lenOfNums>0){
                arr[i]/=10;
                lenOfNums--;
            }
            num+=arr[i];
            num*=10;
        }
        else{
            num+=(arr[i]%10);
            num*=10;
        }
    }
    num/=10;
    if(num%11==0){
        cout<<"OUI"<<endl;
    }
    else{
        cout<<"NON"<<endl;
    }

    return 0;
}