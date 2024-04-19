#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int>& arr){
    vector<int> ansArr;
    set<int> ansSet;
    for(int i: arr){
        int temp = i;
        while(temp != 0){
            int t = temp%10;
            ansSet.insert(t);
            temp /= 10;
        }
    }
    for(auto it: ansSet){
        ansArr.push_back(it);
    }
    return ansArr;
}

int main(){
    int totalInp;
    cin>>totalInp;
    int iter = 0;
    while(iter < totalInp){
        int size;
        cin>>size;
        vector<int> inp(size, 0);

        for(int i = 0; i < size; i++){
            int num;
            cin>>num;
            inp[i] = num;
        }

        vector<int> ans = func(inp);
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
        iter++;
    }
    
}
/*
2
3
131 11 48
4
111 222 333 446
*/