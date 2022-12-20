#include<bits/stdc++.h>
using  namespace std;

// HELPER FUNCTIONS

// for swaping two indices
void swap(int arr[], int a, int b){
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

// for finding inde of minimum element
int findMinIndex(int arr[], int start, int end){
    int min = start;
    for(int j=start;j<end;j++){
        if(arr[min]>arr[j+1]){
            min=j+1;
        }
    }
    return min;
}

// for printing the array
void printArray(int arr[],int n, string s){
    // int n = sizeof(arr)/sizeof(arr[0]);
    cout<<s<<endl;
    for (int i = 0; i < n; i++){
        cout<< arr[i]<<" ";
    }
    cout<<"\n-------------";
}


/*
● Bubble Sort:  
    ▸ O(n²) 
    ▸ Every element is checked against the following element, if smaller then swapped else pass
*/
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

/*
● Selection Sort:  
    ▸ O(n²) 
    ▸ For every iteration, the smallest/largest element in the unsorted array is swapped with the first/last element of that array.
*/
int* selectionSort(int arr[], int n){
    int* a =arr;
    for(int i=0;i<n;i++){
        int firstIndex = i;
        int minIndex = findMinIndex(arr,i,n);
        swap(arr,firstIndex,minIndex);
    }
    return a;
}

/*
● Insertion Sort:  
    ▸ O(n²) 
    ▸ For every iteration, tke the element and check if the previous element is smaller-> yes then swap until desired position, else break;
*/
int* insertionSort(int arr[], int n){
    int*a=arr;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr,j,j-1);
            }else{
                break;
            }
        }
    }
    return a;
}

int main(){
    // cin >> n;
    int arr[] ={4,3,9,1,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // printArray(selectionSort(arr, n),"\nSelection Sort");
    printArray(bubbleSort(arr, n),n,"\nBubble Sort");
    // printArray(insertionSort(arr, n),"\nInsertion Sort");
    // int* a = ;
    // printArray(selectionSort(arr, n),"Selection Sort");

}
