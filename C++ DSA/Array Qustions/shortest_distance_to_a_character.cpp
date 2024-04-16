#include<bits/stdc++.h>
using namespace std;

vector<int> MindistanceToaCharacter(string& s, char c){
    vector<int> mpp;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c){
            mpp.push_back(i);
        }
    }
    int j = 0;
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
        if(mpp.size() > 1){
                ans.push_back(min(abs(mpp[j] - i), abs(mpp[j+1] - i)));
        }else{
            ans.push_back(abs(mpp[j] - i));
        }
        if(mpp[j] < i){
            if(j < mpp.size() - 1) j++;
            cout<<mpp[j];
        }
    }
    cout<<endl;
    return ans;
}

int main(){
    string s = "abaa";
    vector<int> ans =  MindistanceToaCharacter(s, 'b');
    for(int c: ans){
        cout<<c<<" ";
    }
}