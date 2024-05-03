#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int l = 0, r = 0;

    while(r < nums.size()) {
        int count = 1;
        while(r + 1 < nums.size() and nums[r] == nums[r + 1]) {
            r++;
            count++;
        }
        for(int i = 0; i < min(2, count); i++) {
            nums[l] = nums[r];
            l++;
        }
        r++;
    }

    return l;
}

int main() {
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    cout<<removeDuplicates(nums)<<"\n";
    for(auto it: nums) {
        cout<<it<<" ";
    }
}