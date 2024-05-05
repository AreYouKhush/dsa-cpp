#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return (a[0] <= b[0]);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 1) return intervals;
    sort(intervals.begin(), intervals.end(), cmp);
    for(auto it: intervals) {
        for(auto i: it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> res;
    vector<int> temp = {intervals[0][0], intervals[0][1]};

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] <= temp[1]) {
            temp[1] = max(temp[1], intervals[i][1]);
        }else {
            res.push_back(temp);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
        }
    }

    if(res.empty() || res.back() != temp) res.push_back(temp);

    return res;
}

int main() {
    // vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals = {{2,2},{1,10},{2,3},{3,4}};
    vector<vector<int>> merged = merge(intervals);
    for(auto it: merged) {
        for(auto i: it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}