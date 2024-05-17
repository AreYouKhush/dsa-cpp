#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(ind == 0) return nums[0] == target;
    if(dp[ind][target] != -1) return dp[ind][target];

    bool nottake = helper(nums, ind - 1, target, dp);
    bool take = false;
    if(target >= nums[ind])
        take = helper(nums, ind - 1, target - nums[ind], dp);

    return dp[ind][target] = take || nottake;
}

bool canPartition(vector<int>& nums) {
    int target = 0;
    for(int i = 0; i < nums.size(); i++) {
        target += nums[i];
    }
    if(target/2.0 != target/2) return false;
    target /= 2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    return helper(nums, nums.size() - 1, target, dp);
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout<<canPartition(nums);
    return 0;
}