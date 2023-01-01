//only implemented in continuous numbers

# include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n){
    //find the max element to get idea about number of elements in the array;
    int k=arr[0]; 
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    // make count array and store the frequncy of each number in the given array
    int count[n]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    // modify the count array, denoting the position of every element in the sorted array
    for(int i=1;i<n;i++){
        count[i]+=count[i-1];
    }

    // make a new sorted array
    int newArr[n];
    for(int i=n-1;i>=0;i--){
        newArr[--count[arr[i]]] =arr[i];
    }

    // print the new sorted array
    for(int i=0;i<9;i++){
        cout<<newArr[i]<<" ";
    }

}

int main(){

    int arr[] = {1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    return 0;
}