#include<bits/stdc++.h>
using namespace std;

// Using monotonic stack technique
vector<int> nextGreaterElements(vector<int>& nums) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unordered_map<int, vector<int>> mpp;
    vector<int> temp(nums.size(), -1);
    stack<int> st;

    for(int i = nums.size() - 1; i >= 0; i--) {
        mpp[nums[i]].push_back(i);
    }

    int idx = 0;
    for(int i = 0; i < nums.size() * 2; i++, idx++) {
        if(i == nums.size()) idx = 0;
        int cur = nums[idx];
        while(!st.empty() && cur > st.top()){
            int val = st.top();
            st.pop();
            if(mpp[val].size() != 0) {
                temp[mpp[val].back()] = cur;
                mpp[val].pop_back();
            }
        }
        st.push(cur);
    }

    return temp;
}

vector<int> nextGreaterElementsOptimized(vector<int>& nums) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = nums.size();
    vector<int> output(n, -1);
    stack<int> st;

    for(int i = 0; i < nums.size()*2; i++){
        while(!st.empty() && nums[st.top()] < nums[i % n]){
            output[st.top()] = nums[i % n];
            st.pop();
        }
        if(i < n) st.push(i);
    }

    return output;
}

int main() {
    vector<int> nums = {1,2,1,3,1};
    // vector<int> res = nextGreaterElement(nums1, nums);
    vector<int> res = nextGreaterElementsOptimized(nums);

    for(auto it: res) {
        cout<<it<<" ";
    }
}