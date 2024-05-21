#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int target, int total, int i, vector<vector<int>>& dp, int offset) {
    if(i == nums.size()) {
        return total == target;
    }
    if(dp[i][total + offset] != -1) return dp[i][total + offset];

    dp[i][total + offset] = helper(nums, target, total + nums[i], i + 1, dp, offset) +
                            helper(nums, target, total - nums[i], i + 1, dp, offset);

    return dp[i][total + offset];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int offset = total;  // Offset to handle negative indices
    vector<vector<int>> dp(nums.size(), vector<int>(2 * total + 1, -1));
    return helper(nums, target, 0, 0, dp, offset);
}

int main() {
    vector<int> nums1 = {1,1,1,1,1};
    int target1 = 3;
    vector<int> nums2 = {1,3,2,4,4,2,4};
    int target2 = 7;

    cout<<findTargetSumWays(nums1, target1)<<endl;
    cout<<findTargetSumWays(nums2, target2)<<endl;

    return 0;
}