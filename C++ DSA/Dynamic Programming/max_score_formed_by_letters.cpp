#include<bits/stdc++.h>
using namespace std;

int helper(vector<string>& words, unordered_map<char, int>& mpp, vector<int>& score, int ind, bool used) {
    if(ind >= words.size()) return 0;

    int nottake = helper(words, mpp, score, ind + 1, used);
    int wScore = 0;
    int f = false;
    int i = 0;

    for(; i < words[ind].size(); i++) {
        if(mpp.find(words[ind][i]) == mpp.end() || mpp[words[ind][i]] == 0) {
            wScore = 0;
            break;
        } else {
            wScore += score[words[ind][i]-'a'];
            mpp[words[ind][i]]--;
        }
    }

    int take = 0;

    if(wScore != 0){
        take = wScore + helper(words, mpp, score, ind + 1, used);
        used = true;
    } else {
        for(int start = 0; start < i; start++) mpp[words[ind][start]]++;
    }

    if(used) {
        for(auto it: words[ind]) {
            mpp[it]++;
        }
    }

    return max(nottake, take);
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    unordered_map<char, int> mpp;
    for(auto it: letters) mpp[it]++;
    return helper(words, mpp, score, 0, false);
}

int main() {
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout<<maxScoreWords(words, letters, score)<<endl;
    return 0;
}