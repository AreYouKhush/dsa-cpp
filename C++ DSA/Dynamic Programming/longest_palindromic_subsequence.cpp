#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
    int i = 0, j = s.size()-1;
    while(i <= j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int helper(string s, int ind, string temp) {
    if(ind < 0) {
        if(check(temp)) return temp.size();
        return 0;
    }

    temp.push_back(s[ind]);
    int pick = helper(s, ind-1, temp);
    temp.pop_back();
    int notpick = helper(s, ind-1, temp);

    return max(pick, notpick);
}

// Naive method
int longestPalindromeSubseq_naive(string s) {
    return helper(s, s.size()-1, "");   
}

// LCS can be directly used by reversing the string s as it will give us the palindromic subsequence already
int longestPalindromeSubseq(string s) {
    string t = "";
    for(int i = s.size()-1; i >= 0; i--) t.push_back(s[i]);

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[s.size()][t.size()];
}

int main() {
    string s = "bbbab";
    cout<<longestPalindromeSubseq(s);
    return 0;
}