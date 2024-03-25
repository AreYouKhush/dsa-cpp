#include<bits/stdc++.h>
using namespace std;

// trick: whenever the question says numbers something about whole numbers until n, see if marking the index by making its value negative helps

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); ++i){
        int temp = abs(nums[i]);
        if(nums[temp - 1] < 0){
            ans.push_back(temp);
        }
        nums[temp - 1] = -nums[temp - 1]; 
    }
    return ans;
}

int main(){
    vector<int> inp = {5,4,3,2,5,3};
    vector<int> ans = findDuplicates(inp);
    for(auto it: ans){
        cout<<it<<" ";
    }
}