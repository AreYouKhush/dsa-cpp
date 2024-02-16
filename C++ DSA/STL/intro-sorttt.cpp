#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end()); // Insertion Sort + Quick Sort + Heap Sort O(nlog(n))

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}