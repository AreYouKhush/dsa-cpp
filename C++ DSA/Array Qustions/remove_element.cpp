#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0, j = nums.size() - 1, count = 0;
    while(i != j){
        cout<<i<<" "<<j<<endl;
        if(j == val){
            j--;
            count++;
        }else if(i == val){
            swap(nums[i], nums[j]);
            j--;
            i++;
            count++;
        }else{
            i++;
        }
    }
    cout<<endl;
    for(auto it: nums){
        cout<<it<<" ";
    }
    for(int k = 0; k<count;k++){
        nums.pop_back();
    }
    return nums.size();
}

int main(){
    vector<int> v{0,1,2,2,3,0,4,2};
    int cnt = removeElement(v, 2);
    // for(auto it: v){
    //     cout<<it<<" ";
    // }
}