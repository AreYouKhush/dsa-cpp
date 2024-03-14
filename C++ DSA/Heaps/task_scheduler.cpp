#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int> pq;
    deque<pair<int, int>> q;
    map<char, int> mpp;
    for(auto it: tasks){
        mpp[it]++;
    }
    for(auto it: mpp){
        pq.push(it.second);
    }
    int time = 0;
    int count = 0;
    while(!pq.empty() || !q.empty()){
        time++;
        if(!pq.empty()){
            int count = pq.top() - 1;
            pq.pop();
            if(count){
                q.push_back({count, time + n});
            }
        }
        if(!q.empty() && q[0].second == time){
            pq.push(q[0].first);
            q.pop_front();
        }
    }
    return time;
}

int main(){
    vector<char> inp = {'A','A','A','B','B','B'};
    cout<<leastInterval(inp, 2);
}