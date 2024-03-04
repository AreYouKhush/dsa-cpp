#include<bits/stdc++.h>
using namespace std;

vector<int> bitManipulation1(int num, int i){
    vector<int> ans;
    double power = pow(2.0, double(i - 1));
    int a1 = num ^ int(power);
    if(a1 > num){
        ans.push_back(0);
    }else{
        ans.push_back(1);
    }
    ans.push_back(a1);
    ans.push_back(num);
    return ans;
}

//Better appraoach
vector<int> bitManipulation2(int num, int i){
    vector<int> ans;
    int mask = 1 << i-1;
    if((num&mask) == 0){
        ans.push_back(0);
    }else{
        ans.push_back(1);
    }
    num = num | mask;
    ans.push_back(num);

    num = num ^ mask;
    ans.push_back(num);

    return ans;
}

int main(){
    int num = 11;
    int i = 2;
    vector<int> ans = bitManipulation2(num, i);
    for(auto it : ans){
        cout<<it<<" ";
    }
}