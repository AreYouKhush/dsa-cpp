#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i != 5; i++)
    {
        v.push_back(((i + i + (i * 2) + 3) * 2) / 3);
    }

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Finding 7: " << binary_search(v.begin(), v.end(), 7) << endl;
    cout << "Finding 11: " << binary_search(v.begin(), v.end(), 11) << endl;

    cout << "Lower Bound: " << lower_bound(v.begin(), v.end(), 7) - v.begin() << endl;

    int a = 5;
    int b = 6;

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    swap(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << s << endl;

    rotate(v.begin(), v.begin(), v.end());

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}