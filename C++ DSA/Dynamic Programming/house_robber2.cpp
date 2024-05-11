#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int res = 0;
    int cycle = 0;
    while(cycle != 2) {
        int prev1 = 0;
        int prev2 = 0;
        for(int i = 1-cycle; i < nums.size()-cycle; i++) {
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        res = max(prev1, res);
        cycle++;
    }
    return res;
}

int main() {
    vector<int> nums = {2,2,1,2,3,5,3,2,1,2,4};
    cout<<rob(nums);
    return 0;
}