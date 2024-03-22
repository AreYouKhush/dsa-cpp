#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequentI(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mpp;
    for(auto it: nums){
        mpp[it]++;
    }
    for(auto it: mpp){
        pq.push({it.second, it.first});
    }
    vector<int> ans;
    while(!pq.empty() && k > 0){
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return ans;
}

vector<int> topKFrequentII(vector<int>& nums, int k) { 
    unordered_map<int, int> mp;
    vector<pair<int, int>> v;
    vector<int> output;
    for(int i=0; i<nums.size(); i++) {
        mp[nums[i]] ++;
    }  
    for(auto i : mp){
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end());
    for(int i=v.size()-1; i>=0 && k!=0 ; i--){
        output.push_back(v[i].second);
        k--;
    }
    return output;   
}

int main(){
    vector<int> inp = {1,1,1,2,2,3,4,3,6,5};
    vector<int> ans = topKFrequentII(inp, 2);
    for(auto it: ans){
        cout<<it<<" ";
    }
}