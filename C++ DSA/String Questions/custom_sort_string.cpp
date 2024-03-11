#include<bits/stdc++.h>
using namespace std;

string customSortString(string order, string s) {
    string ans = "";
    unordered_map<char, int> mpp;
    for(auto it: s){
        mpp[it]++;
    }
    for(auto it: order){
        if(mpp.count(it)){
            while(mpp[it] > 0){
                ans += it;
                mpp[it]--;
            }
        }
    }
    for(auto it: mpp){
        while(it.second > 0){
            ans += it.first;
            it.second--;
        }
    }
    return ans;
}

int main(){
    string order = "abcd";
    string s = "bdgs";
    cout<<customSortString(order, s);
}