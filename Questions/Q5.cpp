// #include <bits/stdc++.h>
#include<iostream>
#include<set>
#include <unordered_set>
using namespace std;

int countDistinct(int arr[], int n)
{
    // Creates an empty hashset
    unordered_set<int> s;
 
    // Traverse the input array
    int res = 0;
    for (int i = 0; i < n; i++) {
 
        // If not present, then put it in
        // hashtable and increment result
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            res++;
        }
    }
 
    return res;
}

int main(){
    int t,n,m;
    //taking input the number of test cases
    cin>>t;
    while(t>0){
        // taking input the values of N and M
        cin>>n>>m;
        int arr[n]; // declaring array of size N

        // taking input for N elements of array
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        // checking for unique votes
        int uniqueVotes=countDistinct(arr,n);

        // final condition check
        if(uniqueVotes>=m){
            cout<<"JANI"<<endl;
        }
        else{
            cout<<"RAMYA"<<endl;
        }

        t--;
    }

}