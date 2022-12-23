# include<bits/stdc++.h>
using namespace std;

int countWays(int nStairs){
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }

    int ans = countWays(nStairs-1) + countWays(nStairs-2);

    return ans;
}

int main(){
    cout<<countWays(5);
    
    return 0;
}