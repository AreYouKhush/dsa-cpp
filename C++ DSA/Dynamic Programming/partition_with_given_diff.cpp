#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int helper(vector<int>& arr, int total, int ind, vector<vector<int>>& dp) {
    if(ind == 0) {
        if(total == 0 && arr[0] == 0) return 2;
        if(total == 0 || total == arr[0]) return 1;
        return 0;
    }
    if(dp[ind][total] != -1) return dp[ind][total];
    int nottake = helper(arr, total, ind-1, dp);
    int take = 0;
    if(arr[ind] <= total) take = helper(arr, total - arr[ind], ind-1, dp);

    return dp[ind][total] = (nottake + take) % mod;
}
// Memoization
int countPartitions_memo(int n, int d, vector<int>& arr) {
    int total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    if(total - d < 0 || (total - d) % 2) return false;
    vector<vector<int>> dp(n, vector<int>(total + 1, -1));
    return helper(arr, (total-d)/2, arr.size() - 1, dp);
}

// Tabulation
int countPartitions(int n, int d, vector<int>& num) {
    int total = 0;
    for(int i = 0; i < n; i++) total += num[i];
    if(total - d < 0 || (total - d) % 2) return false;

    int target = (total-d)/2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if(num[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(num[0] != 0 && num[0] <= target) dp[0][num[0]] = 1;
    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= target; sum++) {
            int nottake = dp[ind-1][sum];
            int take = 0;
            if(num[ind] <= sum) take = dp[ind-1][sum-num[ind]];

            dp[ind][sum] = nottake + take;
        }
    }
    return dp[n-1][target];
}

int main() {
    vector<int> arr1 = {5,2,6,4};
    cout<<countPartitions(arr1.size(), 3, arr1)<<endl;
    vector<int> arr2 = {1,1,1,1};
    cout<<countPartitions(arr2.size(), 0, arr2)<<endl;
    return 0;
}