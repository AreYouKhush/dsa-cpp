#include<bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int n) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto it: arr){
        pq.push(it);
    }

    map<int, int> mpp;
    int rank = 1;

    while(!pq.empty()){
        if(!mpp.count(pq.top())){
            mpp[pq.top()] = rank;
            rank++;
        }
        pq.pop();
    }
    vector<int> ans;
    for(auto it: arr){
        ans.push_back(mpp[it]);
    }
    return ans;
}

int main(){
    vector<int> vec = {1,2,6,9,2};
    vector<int> rank = replaceWithRank(vec, 5);
    for(auto it: rank){
        cout<<it<<" ";
    }
} 