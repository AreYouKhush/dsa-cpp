#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pairs;

int main(){
    map<char, int> m;
    string inp;
    cout<<"Enter the string: ";
    cin>>inp;
    for(int i = 0; i < inp.size(); i++){
        char x = inp[i];
        m[x]++;
    }
    // for(auto &pr : m){
    //     cout<<pr.first<<" "<<pr.second<<endl;
    // }

    set<pair<int, char>> s;
    for(auto &it: m){
        // pairs x = ;
        s.insert(make_pair(it.second, it.first));
    }

    // for(auto &it : s){
    //     cout<<it.first<<" "<< it.second<<endl;
    // }

    string ans = "";
    // set<pairs> :: iterator it;
    for(auto &it : s){
        cout<<(it).first<<" "<<(it).second<<endl;
        for(int i = 0; i < (it).first; i++){
            ans += (it).second;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}