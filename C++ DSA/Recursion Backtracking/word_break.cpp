#include<bits/stdc++.h>
using namespace std;

void helper(string s, unordered_set<string>& wd, int ind, vector<string>& res, vector<string>& cur) {

    if(ind >= s.size()) {
        if(cur.size() != 0) {
            string t = "";
            for(auto it: cur) {
                t += it;
                t += " ";
            }
            t.pop_back();
            res.push_back(t);
        }
        return;
    }

    string temp = "";
    for(int i = ind; i < s.size(); i++) {
        temp += s[i];
        if(wd.find(temp) != wd.end()) {
            if(cur.size() == 0) {
                cur.push_back(temp);
            }else {
                cur.push_back(temp);
            }
            helper(s, wd, i + 1, res, cur);
            cur.pop_back();
        }
    }

}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> res;
    unordered_set<string> wd;
    vector<string> cur;
    for(auto it: wordDict) wd.insert(it);
    helper(s, wd, 0, res, cur);
    return res;
}

int main() {
    vector<string> wordDict1 = {"cat","cats","and","sand","dog"};
    vector<string> wordDict2 = {"cat","cats","and","sand","dog","c","a","t","s","n","d","o","g"};
    string s = "catsanddogcatsanddog";
    vector<string> res = wordBreak(s, wordDict1);
    for(auto it: res) {
        cout<<it<<endl;
    }
    cout<<endl;
    res = wordBreak(s, wordDict2);
    for(auto it: res) {
        cout<<it<<endl;
    }
    return 0;
}