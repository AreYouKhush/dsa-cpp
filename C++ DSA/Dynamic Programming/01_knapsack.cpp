#include<bits/stdc++.h>
using namespace std;

// Greedy fails because of uniformity law.

int helper(int W, int wt[], int val[], int ind, vector<vector<int>>& dp) {
    if(ind == 0) {
        if(wt[ind] <= W) return val[ind];
        return 0;
    }
    if(W == 0) return 0;
    if(dp[ind][W] != -1) return dp[ind][W];
    int notpick = 0 + helper(W, wt, val, ind-1, dp);
    int pick = INT_MIN;
    if(W >= wt[ind])
        pick = val[ind] + helper(W-wt[ind], wt, val, ind-1, dp);

    return dp[ind][W] = max(notpick, pick);
}

int knapSack_memo(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return helper(W, wt, val, n-1, dp);
}

int knapSack_tab(int W, int wt[], int val[], int n) { 
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
    for(int i = 0; i <= n; i++) {
        for(int s = 0; s <= W; s++) {
            if(i == 0 || s == 0)
                dp[i][s] = 0;
            else if(wt[i-1] <= s)
                dp[i][s] = max(val[i-1] + dp[i-1][s - wt[i-1]], 
                               dp[i-1][s]);
            else 
                dp[i][s] = dp[i-1][s];
        }
    }
    return dp[n][W];
}

// space optimization
int knapSack(int W, int wt[], int val[], int n) {
    vector<int> prev(W+1, 0);
    for(int i = 0; i < n; i++) {
        vector<int> cur(W+1, 0); 
        for(int s = 0; s <= W; s++) {
            int notpick = 0 + prev[s];
            int pick = INT_MIN;
            if(s >= wt[i])
                pick = val[i] + prev[s-wt[i]];
            cur[s] = max(notpick, pick);
        }
        prev = cur;
    }
    return prev[W];
}

int main() {
    int val[] = {1,2,3};
    int wt[] = {4,5,1};
    int W = 4;
    cout<<knapSack(W, wt, val, 3)<<endl;
    return 0;
}