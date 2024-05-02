#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unordered_map<int, int> mpp;
    for(int i = 0; i < nums2.size(); i++){
        mpp[nums2[i]] = -1;
        for(int j = i + 1; j < nums2.size(); j++){
            if(nums2[j] > nums2[i]) {
                mpp[nums2[i]] = nums2[j];
                break;
            }
        }
    }
    for(auto& it: nums1) {
        it = mpp[it];
    }
    return nums1;
}

// Using monotonic stack technique
vector<int> nextGreaterElementOptimized(vector<int>& nums1, vector<int>& nums2) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unordered_map<int, int> mpp;
    stack<int> st;
    for(int i = 0; i < nums1.size(); i++) {
        mpp[nums1[i]] = i;
        nums1[i] = -1;
    }
    for(int i = 0; i < nums2.size(); i++) {
        int cur = nums2[i];
        while(!st.empty() && cur > st.top()){
            int val = st.top();
            st.pop();
            nums1[mpp[val]] = cur;
        }
        if(mpp.find(cur) != mpp.end()) {
            st.push(cur);
        }
    }
    return nums1;
}

int main() {
    vector<int> nums1 = {3,5,1};
    vector<int> nums2 = {0,3,1,0,4,5,2,0};
    // vector<int> res = nextGreaterElement(nums1, nums2);
    vector<int> res = nextGreaterElementOptimized2(nums1, nums2);

    for(auto it: res) {
        cout<<it<<" ";
    }
}