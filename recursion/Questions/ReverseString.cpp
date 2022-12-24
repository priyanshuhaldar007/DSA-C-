#include <iostream>

using namespace std;

void reverseStr(string s){
    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverseStr(ros);
    cout<<s[0];
}
string reverse(string &s, int i, int j){
    if(i>j){
        return "";
    }
    swap(s[i],s[j]);
    reverse(s,i+1,j-1);
}

int main()
{
    string s = "suresh";
    reverseStr(s);
    reverse(s,0,s.length()-1);
    cout<<endl<<s;

    return 0;
}