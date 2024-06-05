#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(target < nums[0]) return 0;
        if(target > nums.back()) return nums.size();
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid+1 < nums.size() && nums[mid] < target && nums[mid + 1] > target) return mid+1;
            else if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

int main() {
    return 0;
}