#include<bits/stdc++.h>
using namespace std;

// Greedy does not work here
/*
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    int last = coins.size() - 1;
    int coinsNeeded = 0;
    int tempAmount = 0;
    while(last >= 0){
        if(tempAmount + coins[last] <= amount){
            tempAmount += coins[last];
            coinsNeeded++;
        }else{
            last--;
        }
    }
    if(tempAmount != amount){
        return -1;
    }
    return coinsNeeded;
}
*/

int helper(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
    if(ind == 0) {
        if(amount % coins[ind] == 0) return amount/coins[ind];
        return 1e9;
    }
    if(dp[ind][amount] != -1) return dp[ind][amount];

    int notpick = 0 + helper(coins, amount, ind-1, dp);
    int pick = INT_MAX;
    if(amount >= coins[ind])
        pick = 1 + helper(coins, amount - coins[ind], ind, dp);

    return dp[ind][amount] =  min(notpick, pick);
}

int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return helper(coins, amount, coins.size() - 1, dp);
}

int main() {
    vector<int> coins1 = {186,419,83,408};
    int amount1 = 6249;
    vector<int> coins2 = {9,6,5,1};
    int amount2 = 11;
    cout<<coinChange(coins1, amount1)<<endl;
    cout<<coinChange(coins2, amount2)<<endl;

    return 0;
}