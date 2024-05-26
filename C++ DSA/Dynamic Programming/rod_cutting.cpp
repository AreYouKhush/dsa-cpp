#include<bits/stdc++.h>
using namespace std;

int helper(int price[], int n, int cut, vector<vector<int>>& dp) {
    if(cut > n) return 0;
    if(dp[n][cut] != -1) return dp[n][cut];
    int nottake = 0 + helper(price, n, cut+1, dp);
    int take = 0;
    if(cut <= n) {
        take = price[cut-1] + helper(price, n - cut, cut, dp);
    }

    return dp[n][cut] = max(nottake, take);
}

int cutRod(int price[], int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return helper(price, n, 1, dp);
}

int main() {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = sizeof(prices)/sizeof(prices[0]);
    cout<<cutRod(prices, N);
    return 0;
}