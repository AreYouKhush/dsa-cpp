#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {23,15,99,25,16,33,77,91,10,12,14};
    vector<int> hash(10, 0);

    for(int i = 0; i < nums.size(); i++){
        int idx = nums[i] % 10;
        int temp = idx;
        if(hash[idx] == 0) hash[idx] = nums[i];
        else{
            while(hash[idx] != 0) {
                idx++;
                if(temp == idx) break;
                if(idx == hash.size()) idx = 0;
            }
            hash[idx] = nums[i];
        }
    }

    for(auto it: hash) {
        cout<<it<<" ";
    }
}