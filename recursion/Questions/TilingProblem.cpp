# include<bits/stdc++.h>
using namespace std;

int TilingWays(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }

    return TilingWays(n-1) + TilingWays(n-2);
}

int main(){
    cout<<TilingWays(4);
    
    return 0;
}