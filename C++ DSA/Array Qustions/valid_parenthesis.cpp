#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int leftMin = 0, leftMax = 0;
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0;
        }
        
        return leftMin == 0;
    }
};

int main(){
    Solution sol = Solution();
    string s = "*(*)";
    cout<<sol.checkValidString(s);
}