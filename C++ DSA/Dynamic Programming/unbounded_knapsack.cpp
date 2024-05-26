#include<bits/stdc++.h>
using namespace std;

int helper(int N, int W, int val[], int wt[], vector<vector<int>>& dp) {
    if(N < 0) {
        return 0;
    }
    if(dp[N][W] != -1) return dp[N][W];

    int nottake = 0 + helper(N-1, W, val, wt, dp);
    int take = 0;
    if(W >= wt[N])
        take = val[N] + helper(N, W - wt[N], val, wt, dp);

    return dp[N][W] = max(nottake, take);
}

int knapSack_memo(int N, int W, int val[], int wt[]){
    vector<vector<int>> dp(N, vector<int>(W+1, -1));
    return helper(N-1, W, val, wt, dp);
}

int knapSack(int N, int W, int val[], int wt[]){
    vector<vector<int>> dp(N, vector<int>(W+1, 0));

    for(int i = 0; i <= W; i++) {
        dp[0][i] = ((int) (i/wt[0])) * val[0];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= W; j++) {
            int nottake = 0 + dp[i-1][j];
            int take = 0;
            if(j >= wt[i])
                take = val[i] + dp[i][j - wt[i]];

            dp[i][j] = max(nottake, take);
        }
    }

    return dp[N-1][W];
}

int main() {
    int val[] = {1, 1};
    int wt[] = {2, 1};
    int W = 3;
    int N = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(N, W, val, wt);
    return 0;
}