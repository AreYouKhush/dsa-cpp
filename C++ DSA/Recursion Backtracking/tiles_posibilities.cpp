#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum = 0;
    string str = "";
    unordered_map<char, int> mpp;

    void helper(string& tiles, int maxSize) {
        if (!str.empty()) {
            sum++;
        }
        for (auto& [key, count] : mpp) {
            if (count > 0) {
                str += key;
                mpp[key]--;
                helper(tiles, maxSize);
                mpp[key]++;
                str.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        for (char c : tiles) {
            mpp[c]++;
        }
        helper(tiles, tiles.size());
        return sum;
    }
};

int main() {
    return 0;
}