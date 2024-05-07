#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& board) {
    queue<vector<int>> q;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if((i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) && board[i][j] == 'O'){
                q.push({i, j});
            }else if(board[i][j] == 'O'){
                board[i][j] = 'F';
            }
        }
    }
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            vector<int> coords = q.front();
            q.pop();
            for(auto dir: directions){
                int row = dir[0] + coords[0];
                int col = dir[1] + coords[1];
                if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) continue;
                if(board[row][col] == 'F'){
                    board[row][col] = 'O';
                    q.push({row, col});
                }
            }
        }
    }

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'F') board[i][j] = 'X';
        }
    }

}

int main() {
    vector<vector<char>> grid = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','O','X'}};
    solve(grid);
    for(auto it: grid){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}