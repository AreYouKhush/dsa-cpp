#include<bits/stdc++.h>
using namespace std;

vector<string> all_longest_common_subsequences(string s, string t) {
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    string s = "abaaa", t = "baabaca";
    vector<string> res = all_longest_common_subsequences(s, t);
    for(auto it: res) {
        cout<<it<<" ";
    }
    return 0;
}