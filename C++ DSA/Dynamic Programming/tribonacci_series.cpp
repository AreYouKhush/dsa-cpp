#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        int curr = 0;
        int series = 3;
        while(series <= n) {
            curr = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = curr;
            series++;
        }
        return curr;
    }
};

int main() {
    Solution s1 = Solution();
    cout<<s1.tribonacci(37);
}