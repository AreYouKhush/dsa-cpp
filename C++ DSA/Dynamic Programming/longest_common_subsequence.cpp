#include<bits/stdc++.h>
using namespace std;

int helper(string text1, string text2, int m, int n, vector<vector<int>>& dp) {
    if(m < 0 || n < 0) return 0;
    if(dp[m][n] != -1) return dp[m][n];

    int match = 0;
    int notmatchleft = 0;
    int notmatchright = 0;
    if(text1[m] == text2[n]) {
        match = 1 + helper(text1, text2, m-1, n-1, dp);
    }else{
        notmatchleft = 0 + helper(text1, text2, m-1, n, dp);
        notmatchright = 0 + helper(text1, text2, m, n-1, dp);
    }

    return dp[m][n] = max(match, max(notmatchleft, notmatchright));
}

int longestCommonSubsequence_memo(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return helper(text1, text2, text1.size()-1, text2.size()-1, dp);
}

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));

    for(int i = 1; i <= text1.size(); i++) {
        for(int j = 1; j <= text2.size(); j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string res = "";
    int i = text1.size(), j = text2.size();
    while(i > 0 && j > 0) {
        if(text1[i-1] == text2[j-1]) {
            res += text1[i-1];
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;
    return dp[text1.size()][text2.size()];
}

int main() {
    string text1 = "abaaa";
    string text2 = "baabaca";
    cout<<longestCommonSubsequence(text1, text2);
    return 0;
}