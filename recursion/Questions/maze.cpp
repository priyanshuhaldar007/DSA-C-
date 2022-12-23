# include<bits/stdc++.h>
using namespace std;

int mazePaths(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return mazePaths(n,i+1,j) + mazePaths(n,i,j+1);
}

int main(){
    cout<<mazePaths(3,0,0);
    
    return 0;
}