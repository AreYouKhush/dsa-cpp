#include<bits/stdc++.h>
using namespace std;

int MOD = (int)1e9+7;

// Top-down
long long int topDown(long long int n, vector<long long int>& dp) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (topDown(n - 1, dp) + topDown(n - 2, dp)) % MOD;
}

//bottom-up
long long int bottomUp(long long int n) {
    vector<long long int> dp(n + 1, -1);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}

//optimized
long long int opti(long long int n) {
    if(n <= 1) return n;
    int p1 = 0;
    int p2 = 1;
    int res;
    for(int i = 2; i <= n; i++) {
        res = (p1 + p2) % MOD;
        p1 = p2;
        p2 = res;
    }

    return res;
}
// n <= 43427
int main() {
    long long int n;
    cin>>n;
    vector<long long int> dp(n+1, -1);
    long long int topDownRes = topDown(n, dp);
    long long int bottomUpRes = bottomUp(n);
    long long int optimalRes = opti(n);
    if(topDownRes == bottomUpRes && optimalRes == topDownRes){
        cout<<topDownRes;
    }
}

// Recursion (Top - down) -> Tabulation (Bottom - Up)
// Answer to base case         Base case to required answer