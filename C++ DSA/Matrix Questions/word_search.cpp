#include<bits/stdc++.h>
using namespace std;

#define REP(i,j,k) for (int i = j; i < k; i++)

bool exist(vector<vector<char>>& board, string word) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }   
            board[i][j] = temp; 
            return false;
        };
        int i = 0;
        int j = 0;
        REP(i, 0, m) {
            REP(j, 0, n) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

int main(){
    vector<vector<char>> mat = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<exist(mat, "ABCB");
}