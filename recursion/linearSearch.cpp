#include <iostream>
using namespace std;
bool search(int arr[],int size,int target){
    if(arr[0]==target){
        return true;
    }else if(size==0){
        return false;
    }
    search(arr+1,size-1,target);
}
int main(){
    int arr[6]={2,3,6,4,9,5};
    int target =7;
    int size=6;
    cout<<search(arr,size,target);
    return 0;
    
}