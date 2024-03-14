#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size() % groupSize) return false;
    map<int, int> mpp;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto it: hand){
        mpp[it]++;
    }
    for(auto it: mpp){
        pq.push(it.first);
    }
    while(!pq.empty()){
        int first = pq.top();
        for(int i = first; i < first + groupSize; i++){
            if(!mpp.count(i)){
                return false;
            }
            mpp[i]--;
            if(mpp[i] == 0){
                if(i != pq.top()){
                    return false;
                }
                pq.pop();
            }
        }
    }
    return true;
}

int main(){
    vector<int> inp{1,2,3,6,2,3,4,7,8};
    cout<<(isNStraightHand(inp, 3) ? "true" : "false");
}