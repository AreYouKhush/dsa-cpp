#include<bits/stdc++.h>
using namespace std;

void helper(vector<string>& res, string& temp, int n, int open, int close) {
    if(open == n && close == n) {
        res.push_back(temp);
        return;
    };
    if(open < n){
        temp.push_back('(');
        helper(res, temp, n, open + 1, close);
        temp.pop_back();
    }

    if(close < open){
        temp.push_back(')');
        helper(res, temp, n, open, close + 1);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string temp;
    helper(res, temp, n, 0, 0);
    return res;
}

int main() {
    int n = 12;
    vector<string> res = generateParenthesis(n);
    for(auto it: res) {
        cout<<it<<"\n";
    }
}