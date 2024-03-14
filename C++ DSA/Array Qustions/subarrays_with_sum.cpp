#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        preSum += nums[i];
        int remaining = preSum - goal;
        ans += mpp[remaining];
        mpp[preSum]++;
    }
    return ans;
}

int main(){
    vector<int> inp = {1,0,1,0,1};
    int goal = 2;
    cout<<numSubarraysWithSum(inp, goal);
}