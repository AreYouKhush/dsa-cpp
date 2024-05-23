#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& nums, int k, int ind, vector<int>& cur, int curInd, int& res) {
    for(int i = ind; i < nums.size(); i++) {
        if(curInd != -1) {
            while(curInd < cur.size()-1 && abs(cur[curInd] - nums[i]) > k && abs(cur[curInd] - nums[i]) != 0) curInd++;
        }
        if(curInd == -1 || abs(cur[curInd] - nums[i]) != k) {
            if(curInd == -1) curInd = 0;
            cur.push_back(nums[i]);
            res++;
            if(i != nums.size() - 1)
                helper(nums, k, i + 1, cur, curInd, res);
            if(curInd == cur.size() - 1) curInd--;
            cur.pop_back();
        }
    }
}

int beautifulSubsets(vector<int>& nums, int k) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sort(nums.begin(), nums.end());
    vector<int> cur;
    int res = 0;
    helper(nums, k, 0, cur, -1, res);
    return res;
}

int main() {
    vector<int> nums = {2,4,6};
    int k = 2;
    cout<<beautifulSubsets(nums, k)<<endl;
    return 0;
}