#include<bits/stdc++.h>
using namespace std;

long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<long long> delta;
    long long res = 0;
    for(int i = 0; i < nums.size(); i++) {
        delta.push_back((nums[i]^k) - nums[i]);
        res += nums[i];
    }
    sort(delta.begin(), delta.end(), greater<long long>());

    for(int i = 0; i < nums.size(); i += 2) {
        if(i == nums.size() - 1) break;
        long long path_delta = delta[i] + delta[i+1];
        if(path_delta <= 0) break;
        res += path_delta;
    }

    return res;
}

int main() {
    vector<int> nums = {1,2,1};
    int k = 3;
    vector<vector<int>> edges = {{0,1}, {0,2}};
    cout<<maximumValueSum(nums, k, edges);
    return 0;
}