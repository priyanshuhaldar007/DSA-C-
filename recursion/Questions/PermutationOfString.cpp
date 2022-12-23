# include<bits/stdc++.h>
using namespace std;

void PermutationOfString(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<s.length();i++){
        char c = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);

        PermutationOfString(ros, ans+c);
    }
}

int main(){
    PermutationOfString("ABC","");
    
    return 0;
}