#include<bits/stdc++.h>
using namespace std;

int xor_0tob(int b){
    if(b%4 == 0){
        return b;
    }
    else if(b%4 == 1){
        return 1;
    }
    else if(b%4 == 2){
        return b+1;
    }
    else if(b%4 == 3){
        return 0;
    }
    return 0;
}

int main(){
    int a,b;
    cin>>a>>b;
    int res = xor_0tob(b) ^ xor_0tob(a-1);
    
    cout<<res;

    return 0;
}