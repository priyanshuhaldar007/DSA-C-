# include<bits/stdc++.h>
using namespace std;

int calPower(int a, int b){
    if(b==0){
        return 1;
    }
    return a*calPower(a, b-1);
}

int main(){

    int res = calPower(3,2);
    cout<<res;
    
    return 0;
}