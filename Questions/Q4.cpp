// record breaker
// record breaking day should satisfy the following 2 conditions:
// 1. no of visitors on that day should be strictly larger than the no of visitors before
// 2. either it's the last day , or the no of visitors on the day should be strictly larger than the following day
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxVi=arr[0];
    int rbDays=0;

    if(n==1){
        cout<<1;
        return 0;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>maxVi && arr[i]> arr[i+1]){
            rbDays++;
            maxVi = max(maxVi, arr[i]);
        }
    }
    if (maxVi<arr[n-1]){
        rbDays++;
    }
    
    cout<< rbDays;

    return 0;
}