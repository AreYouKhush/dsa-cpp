#include<bits/stdc++.h>
using namespace std;


void helper(vector<string>& res, string next, string combination, vector<string> letters){
    if(next.empty()){
        res.push_back(combination);
    }else{
        string let = letters[next[0]-'2'];
        for(char l: let) {
            helper(res, next.substr(1), combination + l, letters);
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> letters = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;

    helper(res, digits, "", letters);
    return res;
}

int main(){
    string s = "23456789";
    vector<string> res = letterCombinations(s);
    for(auto it: res){
        cout<<it<<" ";
    } 
} 