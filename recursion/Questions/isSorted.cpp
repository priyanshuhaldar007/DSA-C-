# include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[size-1]<arr[size-2]){
        return false;
    }
    isSorted(arr,size-1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    cout<<isSorted(arr,5);
    
    return 0;
}