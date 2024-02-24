#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[2] == b[2]){
        return a[0] < b[0];
    }else{
        return a[2] < b[2];
    }
}

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    unordered_set<int> whoKnow = {0, firstPerson};
    for(auto it:whoKnow){
        cout<<it<<" ";
    }cout<<endl;
    sort(meetings.begin(), meetings.end(), cmp);

    unordered_map<int,vector<int>> mpp;
    for(int i = 0; i < meetings.size(); i++){
        if(mpp.count(meetings[i][2])){
            if(find(whoKnow.begin(), whoKnow.end(), meetings[i][0]) != whoKnow.end() || find(whoKnow.begin(), whoKnow.end(), meetings[i][1]) != whoKnow.end()){
                whoKnow.insert(meetings[i][1]);
                whoKnow.insert(meetings[i][0]);
                mpp[meetings[i][2]].push_back(meetings[i][1]);
            }
        }else{
            if(find(whoKnow.begin(), whoKnow.end(), meetings[i][0]) != whoKnow.end() || find(whoKnow.begin(), whoKnow.end(), meetings[i][1]) != whoKnow.end()){
                whoKnow.insert(meetings[i][1]);
                whoKnow.insert(meetings[i][0]);
                mpp[meetings[i][2]] = {meetings[i][0], meetings[i][1]};
            }
        }
    }

    vector<int> ans;
    for(auto it: whoKnow){
        ans.push_back(it);
    }

    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> meetings =  {{3,1,3},{1,2,2},{0,3,3}};
    int firstPerson = 3;
    vector<int> ans = findAllPeople(n, meetings, firstPerson);
    for(auto it:ans){
        cout<<it<<" ";
    }
}