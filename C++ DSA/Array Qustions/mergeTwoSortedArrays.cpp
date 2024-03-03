#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b){
    vector<int> ans;
    int aiter = 0, biter = 0;
    while(biter < b.size() && aiter < a.size()){
        if(ans.size() > 0 && a[aiter] == ans[ans.size() - 1]){
            aiter++;
            continue;
        }
        if(ans.size() > 0 && b[biter] == ans[ans.size() - 1]){
            biter++;
            continue;
        }
        if(a[aiter] > b[biter]){
            ans.push_back(b[biter]);
            biter++;
        }else{
            ans.push_back(a[aiter]);
            aiter++;
        }
    }
    while(aiter < a.size()){
        if(ans.size() > 0 && a[aiter] == ans[ans.size() - 1]){
            aiter++;
            continue;
        }
        ans.push_back(a[aiter]);
        aiter++;
    }
    while(biter < b.size()){
        if(ans.size() > 0 && b[biter] == ans[ans.size() - 1]){
            biter++;
            continue;
        }
        ans.push_back(b[biter]);
        biter++;
    }
    return ans;
}

vector<int> unionMergeUsingSet(vector<int>& a, vector<int>& b){
    set<int> st;
    for(auto it: a){
        st.insert(it);
    }
    for(auto it: b){
        st.insert(it);
    }
    vector<int> ans;
    for(auto it: st){
        ans.push_back(it);
    }
    return ans;
}

int main(){
    vector<int> a{3,4,5,6,6,7,8};
    vector<int> b{1,2,3,3,6,9,10,10,10,10,10,21};
    vector<int> merged = merge(a, b);
    // vector<int> merged = unionMergeUsingSet(a, b);
    for(auto it: merged){
        cout<<it<<" ";
    }
}