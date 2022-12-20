#include<bits/stdc++.h>
using namespace std;

int* ab(){
    int arr[]={1,2,4};
    int* a =arr;

    return a;
}

void swap(int arr[], int a, int b){
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

int main(){
    
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i <= n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i <= n; i++){
        cout<< arr[i]<<" ";
    }

    return 0;
}