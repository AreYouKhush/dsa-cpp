#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int>& arr, int ind, int target, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;
    if(dp[ind][target] != -1) return dp[ind][target];
    bool nottake = helper(arr, ind-1, target, dp);

    bool take = false;
    if(target >= arr[ind])
        take = helper(arr, ind-1, target - arr[ind], dp);

    return dp[ind][target] = take || nottake;
}
// Memoization
bool isSubsetSum_memo(vector<int>arr, int sum){
    vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
    return helper(arr, arr.size() - 1, sum, dp);
}

bool isSubsetSum(vector<int>& arr, int sum) {
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, false));
    for(int i = 0; i < arr.size(); i++) dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int i = 1; i < arr.size(); i++) {
        for(int t = 1; t <= sum; t++) {
            bool nottake = dp[i - 1][t];
            bool take = false;
            if(t >= arr[i])
                take = dp[i - 1][t - arr[i]];
            dp[i][t] = take || nottake;
        }
    }
    return dp[arr.size()-1][sum];
}

int main() {
    vector<int> nums = {5,8,4,5,2,1,8,4};
    cout<<isSubsetSum_memo(nums, 7)<<endl;
    return 0;
}