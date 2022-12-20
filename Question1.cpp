#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s,s1;
	    cin>>s;
	    s1=s;
	    int len = s.length();
		if(len==1){
            cout<<"YES"<<endl;
		}
		else{
			s1.erase(0,1);
			s1.push_back(s.at(len-1));
			
			s.pop_back();
			string temp ="";
			temp+=s1.at(len-2);
			s.insert(0,temp);
			if(!(s1.compare(s))){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
