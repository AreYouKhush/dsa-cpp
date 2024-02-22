#include<bits/stdc++.h>
using namespace std;

void frequencyUsingMap(string &s){
    map<char, int> mpp;
    for(int i = 0; i < s.size(); i++){
        mpp[s[i]]++;
    }
    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

bool checkBefore(string &s, int i, char c){
    for(int j = 0; j < i; j++){
        if(c == s[j]){
            return true;
        }
    }
    return false;
}

void withoutMapOrSet(string &s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(!checkBefore(s, i, s[i])){
            cout<<s[i]<<": ";
        }else{
            continue;
        }
        for(int j = i; j < s.size(); j++){
            if(s[i] == s[j]){
                count++;
            }
        }
        cout<<count<<endl;
        count = 0;
    }
}

void usingHashMap(string &s){
    vector<int> v(26, 0);
    for(int i = 0; i < s.size(); i++){
        v[abs((int)(s[i]-'z')) - 1]++;
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0){
            cout<<(char)('a'+i)<<"->"<<v[i]<<endl;
        }
    }
}

int main(){
    string s = "khushalsuthar";
    usingHashMap(s);
}