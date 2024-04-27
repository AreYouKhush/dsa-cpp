#include<bits/stdc++.h>
using namespace std;

void combinationSumRec(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int i, int target) {
    if(i >= candidates.size()) {
        if(target == 0) {
            res.push_back(temp);
        }
        return;
    }
    if(candidates[i] <= target) {
        temp.push_back(candidates[i]);
        combinationSumRec(candidates, res, temp, i, target - candidates[i]);
        temp.pop_back();
    }
    combinationSumRec(candidates, res, temp, i+1, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    combinationSumRec(candidates, res, temp, 0, target);
    return res;
}

void combinationSumRec2(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int i, int target) {
    if(target == 0) {
        res.push_back(temp);
        return;
    }
    for(int ind = i; ind < candidates.size(); ind++){
        if(ind > i && candidates[ind] == candidates[ind - 1]) continue;
        if(candidates[ind] > target) break;

        temp.push_back(candidates[ind]);
        combinationSumRec2(candidates, res, temp, ind+1, target-candidates[ind]);
        temp.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp;
    int sum = 0;
    combinationSumRec2(candidates, res, temp, 0, target);
    return res;   
}

int main() {
    vector<int> nums = {10,1,2,7,6,1,5};
    int sum = 8;
    vector<vector<int>> res = combinationSum2(nums, sum);
    for(auto it: res){
        for(auto item: it) {
            cout<<item<<" ";
        }
        cout<<"\n";
    }
}