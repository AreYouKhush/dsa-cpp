#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string temp = "";
    int count = 0;
    for(auto it: s){
        if(it == '('){
            count++;
            temp.push_back(it);
        }else if(it == ')' && count > 0){
            count--;
            temp.push_back(it);
        }else if(it == ')' && count <= 0){
            continue;
        }else{
            temp.push_back(it);
        }
    }

    string res = "";
    count = 0;
    for(int i = temp.size() - 1; i >= 0; i--){
        if(temp[i] == ')'){
            count++;
            res.push_back(temp[i]);
        }else if(temp[i] == '(' && count > 0){
            count--;
            res.push_back(temp[i]);
        }else if(temp[i] == '(' && count <= 0){
            continue;
        }else{
            res.push_back(temp[i]);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string inp = "(dsf))))))((()()()))()()()())))()()))()))())()()()()))()))())))()()()()";
    cout<<minRemoveToMakeValid(inp);
}