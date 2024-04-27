#include<bits/stdc++.h>
using namespace std;

/*
All possible patters from Subsequence

1. Print All the Subsequence
2. Print all Sq which sums to K
3. Print only 1st Sq which sums to K
4. Print the count of Sq which sums to K
*/

// bool allSubsequences(vector<int>& vec, vector<int>& temp, int ind, int sum, int k) {
//     if(ind >= vec.size()) {
//         if(sum == k) {
//             for(auto it: temp){
//                 cout<<it<<" ";
//             }
//             cout<<"\n";
//             return true;
//         }
//         return false;
//     }
//     temp.push_back(vec[ind]);
//     sum += vec[ind];
//     if(allSubsequences(vec, temp, ind+1, sum, k)) return true;
//     sum -= temp.back();
//     temp.pop_back();
//     if(allSubsequences(vec, temp, ind+1, sum, k)) return true;
//     return false;
// }

int allSubsequences(vector<int>& vec, vector<int>& temp, int ind, int sum, int k) {
    if(sum > k) return 0; // if array contains only positive integers
    if(ind >= vec.size()) {
        if(sum == k)
            return 1;
        return 0;
    }
    temp.push_back(vec[ind]);
    sum += vec[ind];
    int l = allSubsequences(vec, temp, ind+1, sum, k);
    sum -= temp.back();
    temp.pop_back();
    int r = allSubsequences(vec, temp, ind+1, sum, k);
    return l + r;
}

int main() {
    vector<int> vec = {3,1,2,1,4};
    vector<int> temp = {};
    int k = 5;
    cout<<allSubsequences(vec, temp, 0, 0, k);
}