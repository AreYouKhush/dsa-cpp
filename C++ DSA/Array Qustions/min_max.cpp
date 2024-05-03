#include<bits/stdc++.h>
using namespace std;

int minMaxGame(vector<int>& nums) {
    int size = nums.size();
    while(size > 1) {
        vector<int> res(size/2, 0);
        int i = 0;
        int idx = 0;
        bool flag = true;
        while(i < nums.size()) {
            int n = 0;
            if(flag) {
                n = min(nums[i], nums[i+1]);
            }else{
                n = max(nums[i], nums[i+1]);
            }
            res[idx] = n;
            i += 2;
            idx++;
            flag = !flag;
        }
        nums = res;
        size = res.size();
    }
    return nums[0];
}

int main() {
    vector<int> nums = {7,9,6,7,2,3,5,6};
    cout<<minMaxGame(nums);
}