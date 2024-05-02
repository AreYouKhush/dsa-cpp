#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    unordered_map<char, vector<int>> mpp;
    for(int i = 0; i < s.size(); i++) {
        mpp[s[i]].push_back(i);
    }

    for(auto it: mpp){
        cout<<it.first<<"---> ";
        for(auto i: it.second){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

    int maxSize = 0;
    pair<int, int> pp = {0, 0};

    for(int i = 0; i < s.size(); i++){
        for(int it = mpp[s[i]].size() - 1; it >= 0; it--) {
            int fp = i;
            int lp = mpp[s[i]][it];
            int flag = true;
            if(lp - fp + 1 < maxSize || fp == lp){
                break;
            }
            while(fp <= lp){
                // cout<<s[fp]<<" "<<s[lp]<<endl;
                if(s[fp] != s[lp]){
                    flag = false;
                    break;
                }
                fp++;
                lp--;
            }
            if(mpp[s[i]][it] - i + 1 == maxSize){
                break;
            }
            if(flag && mpp[s[i]][it] - i + 1 > maxSize) {
                maxSize = mpp[s[i]][it] - i + 1;
                pp.first = i;
                pp.second = mpp[s[i]][it];
                break;
            }
        }
    }
    string res = "";
    if(maxSize == 0){
        res += s[0];
        return res;
    }
    for(int i = pp.first; i <= pp.second; i++){
        res += s[i];
    }
    return res;
}

int main() {
    // string s = "fafddfafddfacarracdttd";
    string s = "bcvad";
    cout<<longestPalindrome(s);
}