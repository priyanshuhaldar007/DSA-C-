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

int main()
{
    string s = "binod";
    reverseStr(s);

    return 0;
}