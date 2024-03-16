#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mpp;
    mpp[0] = 0;
    int preSum = 0;
    int maxLen = 0;
    int i = 0;
    for(i = 0; i < nums.size(); i++){
        preSum += nums[i] == 0 ? -1 : 1;
        if(mpp.count(preSum)){
            maxLen = max(maxLen, (i + 1) - mpp[preSum]);
        }else{
            mpp[preSum] = i + 1;
        }
    }
    return preSum == 0 ? nums.size() : maxLen;
}

int main(){
    vector<int> inp = {0,0,1,0,0,1};
    cout<<findMaxLength(inp);
}