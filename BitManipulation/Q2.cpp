// count number of ones in binary form of a number

#include<iostream>
using namespace std;

/*
repeat until n=0
n = 19 =     010011
n-1 = 18 =   010010
            --------
n & (n-1) =  010010

pass           1  2  3
n= n & (n-1) = 18 16 0
*/
int noOfOnes(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}

int main(){
    int n =16;
    cout<<noOfOnes(n)<<endl;

    return 0;
}