# include<bits/stdc++.h>
using namespace std;
/*
void print(int n){
    if(n==0){
        return;
    }
    print(n-1);
    cout<<n;
}
*/
int print(int n){
    if(n==0){
        return 0;
    }
    print(n-1);
    cout<<n;

    return 0;
}

int main(){
    int i =print(10);
    
    return 0;
}