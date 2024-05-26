#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int maxlen = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(S1[i-1] == S2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;
            maxlen = max(dp[i][j], maxlen);
        }
    }

    return maxlen;
}

int main() {
    string S1 = "ABCDGH", S2 = "ACDGHR";
    int n = 6, m = 6;
    cout<<longestCommonSubstr(S1, S2, n, m);
    return 0;
}