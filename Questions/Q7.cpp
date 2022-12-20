#include <iostream>
#include<string>
#include<climits>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while(t>0){
	    cin>>n;
	    int arr[n];
	    string  s;
	    int minFail=999;
	    
	    for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin>>s;
        for(int i=0;i<n;i++){
            if(s.at(i) == '0' && minFail> arr[i]){
                // cout<<"check1"<<endl;
                minFail = arr[i];
            }
        }
        
        cout<<minFail<<endl;
	    t--;
	}
	return 0;
}
