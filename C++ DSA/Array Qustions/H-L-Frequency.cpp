#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v)
{
    int n = v.size();
    map<int, int> hashh;
    for (int i = 0; i < n; i++)
    {
        hashh[v[i]]++;
    }
    int max = INT_MIN, min = INT_MAX;
    int highest = 0, lowest = 0;

    for(auto i:hashh){
        if(i.second > max){
            max = i.second;
            highest = i.first;
        }
        if(i.second < min){
            min = i.second;
            lowest = i.first;
        }
    }

    return {highest, lowest};
}

int main()
{
    vector<int> vec = {5,9,6,3,8,4,4,2,2,9,8,5,6,5,5,5,5};
    vector<int> ans = getFrequencies(vec);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}