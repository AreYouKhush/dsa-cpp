#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int helper(vector<int>& powarr, int ind, int target, vector<vector<int>>& dp) {
        if(ind == powarr.size()) {
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        long long notpick = helper(powarr, ind+1, target, dp);
        long long pick = 0;
        if(target - powarr[ind] >= 0)
            pick = helper(powarr, ind+1, target-powarr[ind], dp);

        return dp[ind][target] = (pick + notpick) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<int> powarr;
        for(int i = 1; i <= n; i++) {
            int a = (int)pow(i, x);
            if(a <= n) powarr.push_back(a);
            else break;
        }
        vector<vector<int>> dp(powarr.size() + 1, vector<int>(n+1, -1));
        return helper(powarr, 0, n, dp);
    }
};

int main() {
    return 0;
}