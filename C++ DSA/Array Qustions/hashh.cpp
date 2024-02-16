#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void frequency(vector<int> &nums, int n, int m){
    vector<int> hashh(m, 0);
    for(int i = 0; i < n; i++){
        hashh[nums[i] - 1]++;
    }

    for(auto it:hashh){
        cout<<it<<" ";
    }
}

int main(){
    vector<int> vec = {1, 2, 2, 1, 2, 1, 1, 3, 44};
    int n = vec.size();
    int m = *max_element(vec.begin(), vec.end());
    frequency(vec, n, m);
    return 0;
}