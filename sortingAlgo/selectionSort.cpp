#include<bits/stdc++.h>
using namespace std;

int* selectionSort(int arr[],int n){
    int* a = arr;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return a;
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int* sArr = selectionSort(arr, n);
    for (int i = 0; i < n; i++){
        cout<< sArr[i]<<" ";
    }

    return 0;
}