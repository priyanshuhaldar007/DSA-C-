# include<bits/stdc++.h>
using namespace std;

void sayDigits(int n){
    if(n==0){
        return;
    }
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num = n%10;
    sayDigits(n/=10);
    cout<<arr[num]<<" ";
}

int main(){

    sayDigits(412);
    return 0;
}