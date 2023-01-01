# include<bits/stdc++.h>
using namespace std;

//bruteFore
void countInversionBF(int arr[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        for (int j = i+1; j < n; j++){
            if(arr[j]<arr[i]){
                count++;
                cout<<"("<<arr[i]<<","<<arr[j]<<"), ";
            }
        }        
    }
    cout<<endl<<count;
}

//optimised, using mergesort
long long merge(int* arr, int s, int e){
    long long inv =0;
    int mid = s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // copy values
    int mainArrayIndex =s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

    //merge 2 sotred arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;

    while(index1 < len1 && index2 <len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
            inv+=len1-index1;
        }
    }

    while (index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

    return inv;
    
}

long long mergeSort(int *arr, int s, int e){
    long long inv =0;
    if(s<e){
        int mid = s + (e-s)/2;

        // sort left part
        inv+= mergeSort(arr,s,mid);

        //sort right part
        inv+= mergeSort(arr,mid+1,e);

        inv+= merge(arr,s,e);
    }


    return inv;
}

int main(){
    int arr[8]={3,5,6,9,1,2,7,8};
    countInversionBF(arr,8);

    //using merge sort
    cout<<endl<<mergeSort(arr,0,7);
    
    return 0;
}