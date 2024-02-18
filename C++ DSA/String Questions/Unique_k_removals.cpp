#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> m;
    for(int i = 0; i < arr.size(); i++){
        m[arr[i]]++;
    }
    vector<pair<int, int>> v;
    for(auto &it : m){
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto &it : v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    for(auto &it : v){
        while(k != 0 && it.second != 0){
            it.second--;
            k--;
            if(it.second == 0){
                auto i = find(v.begin(), v.end(), it);
                v.erase(i);
            }
        }
    }
    cout<<endl;
    for(auto &it : v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return v.size();
}

int main(){
    vector<int> v{4,3,1,1,3,3,2};
    cout<<findLeastNumOfUniqueInts(v, 3);
}