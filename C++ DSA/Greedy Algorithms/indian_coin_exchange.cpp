#include<bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n){
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    int last = coins.size() - 1;
    int tempAmount = 0;
    while(last >= 0){
        if(tempAmount + coins[last] <= n){
            tempAmount += coins[last];
            ans.push_back(coins[last]);
        }else{
            last--;
        }
    }
    return ans;
}

int main(){
    int n = 2542;
    vector<int> ans = MinimumCoins(n);
    for(auto it: ans){
        cout<<it<<" ";
    }
}