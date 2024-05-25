#include<bits/stdc++.h>
using namespace std;

void allSubsequences(vector<int>& vec, vector<int>& temp, int ind) {
    if(ind >= vec.size()) {
        for(auto it: temp){
            cout<<it<<" ";
        }
        cout<<"\n";
        return;
    }
    temp.push_back(vec[ind]);
    allSubsequences(vec, temp, ind+1);
    temp.pop_back();
    allSubsequences(vec, temp, ind+1);
}

int main() {
    vector<int> vec = {3,1,2};
    vector<int> temp = {};
    allSubsequences(vec, temp, 0);
}