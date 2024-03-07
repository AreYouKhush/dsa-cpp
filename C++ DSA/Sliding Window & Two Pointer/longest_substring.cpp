#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mpp;
    int maxSubstring = 0;
    string tempSubstring = "";
    for(int i = 0; i < s.size(); i++){
        if(!mpp.count(s[i])){
            tempSubstring += s[i];
            if(maxSubstring < tempSubstring.size()){
                maxSubstring = tempSubstring.size();
            }
            mpp[s[i]] = i;
        }else{
            tempSubstring = "";
            i = mpp[s[i]];
            mpp.clear();
        }
    }
    return maxSubstring;
}

int main(){
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s);
}