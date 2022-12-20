/*
Q. Find nth magic no.
1 =  0 0 1 => 5³x0 + 5²x0 + 5¹x1 => 5
2 =  0 1 0 => 5³x0 + 5²x1 + 5¹x0 => 25
3 =  0 1 1 => 5³x0 + 5²x1 + 5¹x1 => 25 + 5 = 30
*/

#include <bits/stdc++.h>
using namespace std;

int getMagicNo(int n){
    int sum = 0;
    int base = 5;
    while(n>0){
        int last = n & 1;
        n = n>>1;
        sum+= last * base;
        base = base *5;
    }
    return sum;
}

int main(){
    cout<<getMagicNo(3);
    return 0;
}