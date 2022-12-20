#include<iostream>
using namespace std;

int main(){
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            if(i+j>999)
                break;
            int c = 1000 - i - j;
            cout<<i<<" "<<j<<" "<<c<<endl;
        }
    }
    return 0;
}