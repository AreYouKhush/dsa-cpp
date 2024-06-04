#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int low = 0, high = nums.size() - 1;
        vector<int> res(2, -1);
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                if(mid-1 < 0) {
                    res[0] = 0;
                    break;
                } else if(nums[mid-1] == target) high = mid-1;
                else {
                    res[0] = mid;
                    break;
                } 
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid + 1;
        }
        if(res[0] == -1) return {-1, -1};
        low = res[0], high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                if(mid+1 >= nums.size()){
                    res[1] = nums.size() - 1;
                    break;
                } else if(nums[mid+1] == target) low = mid + 1;
                else {
                    res[1] = mid;
                    break;
                }
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid + 1;
        }
        return res;
    }
};

int main() {
    return 0;
}