#include <iostream>
using namespace std;
bool binarySearch(int arr[], int start, int target, int end)
{
    int mid = start + (end - start) / 2;
    if(start>end){
        return false;
    }
    else if (target == arr[mid])
    {
        return true;
    }
    else if (target < arr[mid])
    {
        binarySearch(arr, start, target, mid-1);
    }
    else if (target > arr[mid])
    {
        binarySearch(arr, mid+1, target, end);
    }
}

int main()
{
    int arr[] = {1, 2, 4, 8, 9};
    int target = 8;
    int size = sizeof(arr) / sizeof(arr[0]);

    bool ans = binarySearch(arr, 0, target, size-1);

    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
/*
    int start=0,end=size-1;
    while(start<=end){
        int mid = start + (end-start)/2;

        if(target==arr[mid]){
            cout<<mid<<endl;
            break;
        }
        else if(target < mid){
            end = mid-1;
        }
        else if(target > mid){
            start = mid+1;
        }
    }

*/