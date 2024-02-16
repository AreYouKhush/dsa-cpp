#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void loop(vector<int> &v, int count, int num){
    if(count <= num){
        v.push_back(count);
        loop(v, count + 1, num);
    }else{
        return;
    }
}

vector<int> printNos(int x) {
    vector<int> out;
    loop(out, 1, x);
    return out;
}

int main()
{
    int x = 10;
    vector<int> w;
    w = printNos(x);
    for(auto i:w){
        cout<<i<<" ";
    }
    return 0;
}