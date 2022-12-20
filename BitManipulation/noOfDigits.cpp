/*
Get numebr of digits in binary representation

log₁₀(a)  gives the number of digits in a according to decimal number system


*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 10; // number whose digits has to be found
    int b = 2; // base represents the binary representation

    int ans = (int)(log(n)/log(b)) +1;

    cout<<ans;

    return 0;
}