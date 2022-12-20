#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                s1+=arr[i];
            }
            else{
                s2+=arr[i];
            }
        }
        // s1 = 2 0 0 -4
        // s2 = -9 
        s1 = abs(s1);
        s2 = abs(s2);
        cout<<abs(s1-s2)<<endl;
    }
}