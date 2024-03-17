#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int start = newInterval[0];
    int last = newInterval[1];
    for(auto it: intervals){
        if(it[1] < newInterval[0]){
            ans.push_back(it);
        }else{
            start = it[0] < newInterval[0] ? it[0] : newInterval[0];
            break;
        }
    }
    if(ans.size() == intervals.size()){
        ans.push_back(newInterval);
        return ans;
    }else{
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > newInterval[1]){
                break;
            }
            if(intervals[i][1] >= newInterval[1]){
                last = intervals[i][1];
                break;
            }
        }
        newInterval = {start, last};
        ans.push_back(newInterval);
        for(auto it: intervals){
            if(it[0] > newInterval[1]){
                ans.push_back(it);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{3,4},{7,9},{10,13}};
    vector<int> newInterval = {1,2};
    vector<vector<int>> ans = insert(intervals, newInterval);
    for(auto it: ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}