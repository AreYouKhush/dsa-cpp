#include<bits/stdc++.h>
using namespace std;

vector<int> armstrongInRange(int i1, int i2){
    vector<int> ans;
    for(int i = i1; i <= i2; i++){
        int temp = i;
        int arm = 0;
        while(temp != 0){
            int t = temp%10;
            if(t != 0) arm += (t*t*t);
            temp = temp/10;
        }
        if(i == arm){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int i1 = 100;
    int i2 = 400;
    vector<int> ans = armstrongInRange(i1, i2);
    for(int i: ans){
        cout<<i<<" ";
    }
}