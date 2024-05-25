#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void helper(vector<vector<string>>& res, vector<string>& cur, string s, int i) {
    if(i >= s.size()) {
        res.push_back(cur);
    }

    for(int j = i; j < s.size(); j++) {
        if(isPalindrome(s, i, j)) {
            cur.push_back(s.substr(i, j - i + 1));
            helper(res, cur, s, j+1);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> currentList;
    helper(result, currentList, s, 0);
    return result;
}

int main() {
    string s = "abababababa";
    vector<vector<string>> res = partition(s);
    for(auto it: res) {
        for(auto i: it) {
            cout<<i<<", ";
        }
        cout<<endl;
    }
    return 0;
}