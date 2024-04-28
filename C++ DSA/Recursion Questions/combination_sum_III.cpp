#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& res, vector<int>& temp, int k, int n, int curr){
    if(temp.size() == k && n == 0) {
        res.push_back(temp);
        return;
    }
    for(int i = curr; i <= n, i <= 9; i++) {
        temp.push_back(i);
        helper(res, temp, k, n-i, i+1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> temp;
    helper(res, temp, k, n, 1);
    return res;
}

int main(){
    int k = 3;
    int n = 9;
    vector<vector<int>> res = combinationSum3(k, n);
    for(auto it: res){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    } 
}