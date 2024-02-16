#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    set<vector<int>> s;

    vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    sort(vec.begin(), vec.end());
    s.insert(vec);

    s.insert({1,2,3});
    s.insert({3,2,1});
    s.insert({1,2,3});

    for(auto it = s.begin(); it != s.end(); it++){
        Print_Vector(*it);
    }

}