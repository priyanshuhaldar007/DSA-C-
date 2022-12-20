#include<bits/stdc++.h>
using namespace std;

int mainn(){
    int a;
    cin>>a;
    if(a%4 == 0){
        cout<<a<<endl;
    }
    else if(a%4 == 1){
        cout<<1<<endl;
    }
    else if(a%4 == 2){
        cout<<a+1<<endl;
    }
    else if(a%4 == 3){
        cout<<0<<endl;
    }
    return 0;
}