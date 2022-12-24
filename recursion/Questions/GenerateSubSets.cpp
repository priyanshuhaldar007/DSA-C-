# include<bits/stdc++.h>
using namespace std;

void print(vector<int> ans){
    for(int i=0;i<3;i++){
        cout<<ans[i];
    }
    cout<<endl;
}

void generateSubSets(int arr[],vector<int> ans, int i){
    if(i>=3){
        cout<<"{";
        for(int j=0;j<ans.size();j++){
            cout<<ans[j];
        }
        cout <<"}"<< endl;
        return;
    }
    generateSubSets(arr,ans,i+1); //exclude
    ans.push_back(arr[i]);
    generateSubSets(arr,ans,i+1); //include
}

int main(){
    int arr[] = {1,2,3};
    vector<int> ans;
    generateSubSets(arr,ans,0);
    
    return 0;
}