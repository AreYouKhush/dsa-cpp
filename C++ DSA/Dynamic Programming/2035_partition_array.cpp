#include<bits/stdc++.h>
using namespace std;

// TLE cannot figure out myself how to memoize!!!!!
int helper(vector<int>& nums, int total, int sum, int ind, int size) {
    if(ind == nums.size()) return INT_MAX;

    sum += nums[ind];
    size++;
    int pick = helper(nums, total, sum, ind + 1, size);
    sum -= nums[ind];
    size--;
    int notpick = helper(nums, total, sum, ind + 1, size);

    if(size == nums.size()/2)
        return abs((total - sum) - sum);
    return min(notpick, pick);
}

int minimumDifference(vector<int>& nums) {
    int total = 0;
    for(int i = 0; i < nums.size(); i++) {
        total += nums[i];
    }

    return helper(nums, total, 0, 0, 0);
}

int main() {
    vector<int> nums1 = {3,9,7,3};
    vector<int> nums2 = {-36,36};
    vector<int> nums3 = {2,-1,0,4,-2,-9};
    cout<<minimumDifference(nums1)<<endl;
    cout<<minimumDifference(nums2)<<endl;
    cout<<minimumDifference(nums3)<<endl;
    return 0;
}