#include<bits/stdc++.h>
using namespace std;

bool isAnagram(unordered_map<char, int> mpp, string s, int count){
    if(count != s.size()){
        return 0;
    }
    for(auto it: s){
        if(mpp[it] != 0){
            mpp[it]--;
            count--;
        }
    }
    return count == 0 ? 1 : 0;
}

// Time Limit Exceeded
vector<vector<string>> groupAnagramsI(vector<string>& strs) {
    vector<vector<string>> ans;
    for(int i = 0; i < strs.size(); i++){
        vector<string> temp;
        unordered_map<char, int> mpp;
        int count = 0;
        if(strs[i] != "-1"){
            for(auto it: strs[i]){
                mpp[it]++;
                count++;
            }
        }else{
            continue;
        }
        for(int j = i; j < strs.size(); j++){
            if(isAnagram(mpp , strs[j], count)){
                temp.push_back(strs[j]);
                strs[j] = "-1";
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<string>> groupAnagramsII(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for(auto x: strs){
        string word = x;
        sort(word.begin(), word.end());
        mp[word].push_back(x);
    }
    
    vector<vector<string>> ans;
    for(auto x: mp){
        ans.push_back(x.second);
    }
    return ans;
}

int main(){
    vector<string> inp = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagramsII(inp);
    for(auto it: ans){
        for(auto itr: it){
            cout<<itr<<" ";
        }
        cout<<endl;
    }
}