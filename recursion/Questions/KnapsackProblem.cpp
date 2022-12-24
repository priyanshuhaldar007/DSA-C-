/*
i      |   0   |   1   |   2
wt[i]  |  10   |  20   |  30
val[i] | 100   |  50   | 150

cap = 50
*/


# include<bits/stdc++.h>
using namespace std;

int knapsack(int value[], int wt[], int n, int Cap){
    if(n==0 || Cap==0){
        return 0;
    }
    if(wt[n-1]>Cap){
        return knapsack(value, wt,n-1,Cap);
    }
    return max(knapsack(value,wt,n-1,Cap-wt[n-1])+value[n-1],knapsack(value,wt,n-1,Cap));
}

int main(){
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int Cap = 50;

    cout<<knapsack(value,wt,3,Cap);
    
    return 0;
}