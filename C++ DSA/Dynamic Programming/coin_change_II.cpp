#include<bits/stdc++.h>
using namespace std;

int helper(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp) {
    if(ind == coins.size() - 1) {
        if(amount % coins[ind] == 0) return 1;
        return 0;
    }
    if(dp[ind][amount] != -1) return dp[ind][amount];

    int notpick = helper(amount, coins, ind+1, dp);
    int pick = 0;
    if(amount >= coins[ind])
        pick = helper(amount - coins[ind], coins, ind, dp);

    return dp[ind][amount] = notpick + pick;
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return helper(amount, coins, 0, dp);
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 25;
    cout<<change(amount, coins)<<endl;
    return 0;
}