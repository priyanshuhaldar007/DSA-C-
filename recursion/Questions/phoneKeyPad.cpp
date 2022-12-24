# include<bits/stdc++.h>
using namespace std;

void generateCombinations(string nums,vector<string> ans, int i){
      string mapping[] ={"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      if(i>=nums.length()){
        cout<<"{ ";
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout <<"}"<< endl;
        return;
      }
      int number = nums[i]-'0';
      string s = mapping[number];

      for(int j=0;j<s.length();j++){
        string a = "";
        a+=s[j];
        ans.push_back(a);
        // cout<<endl<<i<<" "<<j<<"\n";
        generateCombinations(nums,ans,i+1);
        ans.pop_back();
      }
}

int main(){

    vector<string> ans;
    generateCombinations("23",ans,0);
    
    return 0;
}