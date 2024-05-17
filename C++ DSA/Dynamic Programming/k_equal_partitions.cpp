#include<bits/stdc++.h>
using namespace std;

bool helper(int i, int k, vector<int>& nums, int subsetSum, vector<bool>& used, int target) {
    if(k == 0) return true;
    if(subsetSum == target) {
        return helper(0, k-1, nums, 0, used, target);
    }

    for(int j = i; j < nums.size(); j++) {
        if(j > 0 && !used[j-1] && nums[j] == nums[j-1]) continue;
        if(used[j] || subsetSum + nums[j] > target) continue;

        used[j] = true;
        if(helper(j + 1, k, nums, subsetSum + nums[j], used, target)) return true;
        used[j] = false;
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    int target = 0;
    for(int i = 0; i < nums.size(); i++) {
        target += nums[i];
    }
    if(target % k != 0) return false;
    target /= k;
    vector<bool> used(nums.size(), false);
    return helper(0, k, nums, 0, used, target);
}

int main() {
    vector<int> nums1 = {2,2,2,2,3,4,5};
    vector<int> nums2 = {1,2,3,4,5,2,2,1};
    cout<<canPartitionKSubsets(nums1, 4)<<endl;
    cout<<canPartitionKSubsets(nums2, 4)<<endl;
    return 0;
}