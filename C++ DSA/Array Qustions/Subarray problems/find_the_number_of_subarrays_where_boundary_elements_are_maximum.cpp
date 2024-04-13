#include<bits/stdc++.h>
using namespace std;

// long long numberOfSubarrays(vector<int>& nums) {
//     long long res = 0;
//     long long maxNum = nums[0];
//     int i = 0;
//     int j = 0;
//     while(i < nums.size()){
//         if(j >= nums.size()){
//             i++;
//             j = i;
//             maxNum = nums[i];
//         }else if(i == j){
//             res++;
//             j++;
//             if(j < nums.size()){
//                 maxNum = max(nums[i], nums[j]);
//             }
//         }else if(maxNum == nums[i] && nums[j] == maxNum && i != j) {
//             res++;
//             j++;
//         }else if(maxNum > nums[i]){
//             i++;
//             j = i;
//             maxNum = nums[i];
//         }else if(maxNum > nums[j]){
//             j++;
//         }
//     }
//     return res;
// }

long long numberOfSubarrays(vector<int>& a) {
    vector <pair <int, int>> st;
    long long ans = 0;
    for (auto &x: a){
        while (!st.empty() && st.back().first < x){
            st.pop_back();
        }
        if (st.empty() || st.back().first != x){
            st.emplace_back(x, 1);
        }
        else{
            st.back().second++;
        }
        ans += st.back().second;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,4,3,3,2};
    cout<<numberOfSubarrays(nums)<<endl;
    nums = {3,3,3};
    cout<<numberOfSubarrays(nums)<<endl;
    nums = {1};
    cout<<numberOfSubarrays(nums)<<endl;
    nums = {3,2,18};
    cout<<numberOfSubarrays(nums)<<endl;
}