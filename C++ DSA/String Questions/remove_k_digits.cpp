#include<bits/stdc++.h>
using namespace std;

//Time Complexity :- O((n-k)*n) or O(n^2)
string removeKdigits(string num, int k) {
    if(num.size() - k == 0){
        return "";
    }
    string ans = "";
    int size = num.size() - 1;
    int temp = -1;
    while(ans.size() < num.size() - k){
        char smallDigit;
        int i = temp + 1;
        smallDigit = 'z';
        for(; i <= k + ans.size(); i++){
            // if(num[i] == '0' && ans.size() == 0){
            //     num[i] = 'z';
            //     continue;
            // }
            if(num[i] < smallDigit){
                smallDigit = num[i];
                temp = i;
            }
        }
        ans += smallDigit;
    }
    int i = 0;
    while(ans[i] == '0'){
        i++;
    }
    ans = ans.substr(i);
    return ans;
}

//Time Complexity :- O(n)
string removeKdigitsII(string num, int k){
    string ans = "";
    for(auto c: num){
        while(k && ans.size() && ans.back() > c){
            ans.pop_back();
            k--;
        }
        if(ans.size() || c != '0'){
            ans.push_back(c);
        }
    }
    while(k && ans.size()){
        ans.pop_back();
        k--;
    }
    return ans.size() ? ans : "0";
}

int main(){
    string s = "10001058";
    cout<<removeKdigitsII(s, 3);
}