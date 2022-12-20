#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n=3;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	       cin>>arr[i];
	    }
	    int max=arr[0];
	    int Smax=arr[0];
	    for (int i = 0; i < n; i++) {
	       if(max<arr[i]){
	           Smax = max;
	           max = arr[i];
	       }
	    }
	    cout<<Smax<<endl;
	}
	return 0;
}
