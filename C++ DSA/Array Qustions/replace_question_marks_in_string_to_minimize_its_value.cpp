#include<bits/stdc++.h>
using namespace std;

string minimizeStringValue(string s) {
    char c = 'a';
    map<char, int> mpp;
    int quest = 0;
    for(auto it: s){
        if(it == '?'){
             quest++;   
        }else{
            mpp[it]++;
        }
    }
    int minOcc = INT_MAX;
    if(mpp.count(c) && minOcc > mpp[c]){
        minOcc = mpp[c];
    }
    string tempStr = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '?'){
            int rep = 0;
            while(mpp.count(c) && rep < 27){
                c++;
                rep++;
                if(c > 'z'){
                    c = 'a';
                }
                if(minOcc > mpp[c]){
                    minOcc = mpp[c];
                    break;
                }
            }
            tempStr += c;
            mpp[c]++;
        }
    }
    sort(tempStr.begin(), tempStr.end());
    int i = 0;
    int j = 0;
    while(i < s.size() && j < tempStr.size()){
        while(s[i] != '?'){
            i++;
        }
        s[i] = tempStr[j];
        j++;
        i++;
    }
    return s;
}

int main(){
    string s = "???";
    cout<<minimizeStringValue(s);
}