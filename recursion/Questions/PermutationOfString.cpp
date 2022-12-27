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

//love babbar- by swapping
void PermuteStr(string s, vector<string> ans, int i){
    if(i>=s.length()){
        for(int j=0;j<s.size();j++){
            cout<<s[j]<<" ";
        }
        cout<<endl;
        return ; 
    }
    for(int j=i; j<s.length();j++){
        swap(s[i],s[j]);
        PermuteStr(s,ans,i+1);
        swap(s[i],s[j]);
    }
}

//love babbar- by pushing
void pS(string s, vector<string> ans, int i){
    if(i>=s.length()){
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        return;
    }

    for(int j=i;j<s.length();j++){
        string a = "";
        a+=s[j];
        ans.push_back(a);
        pS(s,ans,i+1);
        ans.pop_back();
    }
}
int main(){
    vector<string> ans;
    // PermutationOfString("ABC","");
    PermuteStr("abc",ans,0);
    
    return 0;
}