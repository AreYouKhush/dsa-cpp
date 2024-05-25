#include<bits/stdc++.h>
using namespace std;

void helperI(vector<vector<int>>& res, vector<int>& nums, vector<int> ds, vector<bool> freq){
    if(ds.size() == nums.size()) {
        res.push_back(ds);
    }
    for(int i = 0; i < nums.size(); i++) {
        if(!freq[i]) {
            freq[i] = true;
            ds.push_back(nums[i]);
            helperI(res, nums, ds, freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}

vector<vector<int>> permuteExtraSpace(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> ds;
    vector<bool> freq(nums.size());
    helperI(res, nums, ds, freq);
    return res;
}


void helper(vector<vector<int>>& res, vector<int>& nums, int index){
    if(index == nums.size()){
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back(nums[i]);
        }
        res.push_back(temp);
        return;
    }
    for(int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        helper(res, nums, index + 1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> res;
    helper(res, nums, 0);
    return res;
}

int main() {
    vector<int> nums = {1,2,3};
    // vector<vector<int>> res = permuteExtraSpace(nums);
    vector<vector<int>> res = permute(nums);
    for(auto it: res) {
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}