#include<bits/stdc++.h>
using namespace std;

void genSubStr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    char c = s[0];
    int code = c;
    string ros = s.substr(1);

    genSubStr(ros, ans);
    genSubStr(ros, ans+c);
    genSubStr(ros, ans+ to_string(code));

}

int main(){

    genSubStr("AB","");
    
    return 0;
}