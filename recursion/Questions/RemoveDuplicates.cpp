#include<bits/stdc++.h>
using namespace std;

string removeDup(string s){
    if(s.length()==0){
        return "";
    }

    char c = s[0];
    string ans = removeDup(s.substr(1));

    if(c==ans[0]){
        return ans;
    }
    return c+ans;
}

int main(){
    cout<<removeDup("aaaabbbeeecdddd");

    return 0;
}