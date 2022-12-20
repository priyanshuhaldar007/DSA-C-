#include<bits/stdc++.h>
using namespace std;

int* bubbleSort(int arr[], int n){
    int* a = arr;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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

    int* sArr = bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
        cout<< sArr[i]<<" ";
    }

    return 0;
}