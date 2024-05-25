#include<bits/stdc++.h>
using namespace std;

void combinations(vector<int> &nums, int index, vector<int> &cur, vector<vector<int>> &ans) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    if(index == nums.size()) {
        ans.push_back(cur);
        return;
    }

    combinations(nums, index + 1, cur, ans);
    cur.push_back(nums[index]);
    combinations(nums, index + 1, cur, ans);
    cur.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = nums.size();
    vector<vector<int>> subsetsv;
    vector<int> cur;
    combinations(nums, 0, cur, subsetsv);
    return subsetsv;
}

void subsetsWithDup(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int ind) {
    if(ind >= nums.size()) {
        res.push_back(temp);
        return;
    }
    
    // all subsets that include nums[ind]
    temp.push_back(nums[ind]);
    subsetsWithDup(nums, res, temp, ind+1);
    temp.pop_back();

    // all subsets that don't include nums[ind]
    while(ind+1 < nums.size() and nums[ind] == nums[ind+1]){
        ind++;
    }
    subsetsWithDup(nums, res, temp, ind+1);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    subsetsWithDup(nums, res, temp, 0);
    return res;
}

int main() {
    vector<int> nums = {1,1,2,2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for(auto it: res){
        for(auto item: it) {
            cout<<item<<" ";
        }
        cout<<"\n";
    }
}