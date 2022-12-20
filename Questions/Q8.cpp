#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

int* bubbleSort(int arr[], int n){
    int *a = arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                //swap
                swap(arr,j,j+1);
            }
        }
    }
    return a;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n];

        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int* sArr = bubbleSort(arr, n);

        int g1=0,g2=0;
        for(int i=0;i<n;i++){
            if(i<m){
                g1+=arr[i];
            }
            else{
                g2+=arr[i];
            }
        }
        cout<<(g2-g1)<<endl;
    }

    return 0;
}