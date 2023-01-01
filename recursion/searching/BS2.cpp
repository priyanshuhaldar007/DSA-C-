#include <iostream>
using namespace std;
int BS(int arr[],int target,int start,int end){
    //base case
    if(arr[0]==target){
        return arr[0];
    }
        while (start<=end)
        {
          int  mid = start+(start-end)/2;
        
         if(target>mid){
           start = BS( arr,target,mid+1, end);
        }
         else if(target<mid){
            end =BS( arr, target, start, mid-1);
         }
      else
      {  return mid;
      }

}
return -1;
}
int main(){

int arr[5]={1,2,3,5,6};
int size =sizeof(arr)/sizeof(arr[0]);
int target =5;
int start=0;
int end =size-1;
int ans =BS( arr,target,start,end);
cout<<"your no is at "<<ans<<"index" ;

    return 0;
}