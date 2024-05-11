#include<bits/stdc++.h>
using namespace std;

// pick and non-pick technique
int f(vector<int>& houses, int ind) {
    if(ind == 0) return houses[ind];
    if(ind < 0) return 0;

    int pick = houses[ind] + f(houses, ind - 2);
    int notpick = 0 + f(houses, ind - 1);

    return max(pick, notpick);
}

// memoization
int fmem(vector<int>& houses, vector<int>& dp, int ind) {
    if(ind == 0) return houses[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int pick = houses[ind] + f(houses, ind - 2);
    int notpick = 0 + f(houses, ind - 1);

    return dp[ind] = max(pick, notpick);
}

// Bottom-up
int rob_bottumup(vector<int>& houses) {
    if(houses.size() == 1) return houses[0];
    vector<int> dp(houses.size() + 1, 0);
    dp[0] = 0;
    dp[1] = houses[0];
    for(int i = 2, j = 1; i < dp.size(), j < houses.size(); i++, j++) {
        dp[i] = max(dp[i-1], houses[j] + dp[i-2]);
    }
    return dp.back();
}

int rob_optimal(vector<int>& houses) {
    int prev1 = 0;
    int prev2 = 0;
    for(auto num: houses){
        int temp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = temp;
    }
    return prev1;
}

int rob(vector<int>& houses) {
    vector<int> dp(houses.size(), -1);
    return fmem(houses, dp, houses.size() - 1);
    // return f(houses, houses.size() - 1);
}

int main() {
    vector<int> houses = {1,2,1,2,3,4,3,2,5,2,1,3};
    // vector<int> houses = {2,1,1,2};
    cout<<rob(houses)<<"\n";
    cout<<rob_bottumup(houses)<<"\n";
    cout<<rob_optimal(houses)<<"\n";
}