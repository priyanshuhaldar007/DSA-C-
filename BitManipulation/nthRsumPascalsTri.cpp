/*
Find the sum of nth row in pascals triangle

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    n-=1;
    int ans = pow(2,n);

    cout<<ans;
}