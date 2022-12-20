#include<bits/stdc++.h>
using namespace std;

int* insertionSort(int arr[], int n){
    int* a = arr;
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    return a;
}

int  main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int* sArr = insertionSort(arr, n);
    for (int i = 0; i < n; i++){
        cout<< sArr[i]<<" ";
    }

    return 0;
}