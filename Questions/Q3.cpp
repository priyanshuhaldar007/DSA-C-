// find the length of maximum contigious subarray
// Time constraint - O(n)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int pd = arr[1]-arr[0];
    int maxLength = 2;
    int currLength = 2;
    for(int i=1;i<n-1;i++){
        if(pd==arr[i+1]-arr[i]){
            currLength++;
        }
        else{
            pd=arr[i+1]-arr[i];
            currLength=2;
        }
        maxLength =max(maxLength,currLength);
    }

    cout<< maxLength;

    return 0;
}