// to find a range prime -- the most efficient approach
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    int num = 40;
    int limit = sqrt(num); // 6
    int arr[num] = {1};
    int index=0; // index integer for arr
    for(int i=2;i<num;i++,index++){
        if(arr[index]==1){
            for(int j=index+i;j<num;j+=i){
                arr[j]=0;
            }
        }
    }

    for(int i=0;i<num-1;i++){
        if(arr[i]==1){
            cout<<i+2<<" is Prime"<<endl;
        }
        else{
            cout<<i+2<<" is not prime"<<endl;
        }
    }

    return 0;
}
/*

arr: 

        2 3 4 5 6 7
        ------------
        0 0 0 0 0 0
        ------------
I       1 0 1 0 1 0    | i=2, index=0
        ------------
II      1 1 1 0 1 0    | i=3, index=1
        ------------
III     1 1 1 0 1 0    | i=4, index=2
        ------------
IV      1 1 1 1 1 0    | i=5, index=3

*/