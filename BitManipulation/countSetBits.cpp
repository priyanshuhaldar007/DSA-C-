#include<bits/stdc++.h>
using namespace std;

int setBits(int n){
    int count =0;

    while(n>0){
        count++;
        n = n & (n-1);
    }
    return count;
}

int main(){
    int n=45;

    string s1 = bitset<8>(n).to_string();
    cout<<s1<<endl;

    cout<<setBits(n);
    return 0;
}