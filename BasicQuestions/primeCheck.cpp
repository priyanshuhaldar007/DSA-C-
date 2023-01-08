#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            cout<<"non-prime";
            return false;
        }
    }
    cout<<"Prime";
    return true;
}
int check(int n, int i){
    if(n<=1){
        return 0;
    }
    if(i==n){
        return 1;
    }
    if(n%i==0){
        return 0;
    }
    check(n,i+1);
}

int main(){
    int num;
    cin>>num;
    // isPrime(num);
    cout<<check(num,2);
    return 0;
}
