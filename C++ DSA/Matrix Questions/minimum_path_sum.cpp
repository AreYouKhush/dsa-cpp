#include<bits/stdc++.h>
#include<limits>
using namespace std;

int minPathSumI(vector<vector<int>>& grid) {
    int rows = grid.size() - 1;
    int columns = grid[0].size() - 1;

    vector<vector<int>> res = grid;
    for(int i = 0; i < res.size(); i++){
        int a = std::numeric_limits<int>::max();
        res[i].push_back(a);
    }
    vector<int> temp;
    for(int j = 0; j < res[0].size(); j++){
        int a = std::numeric_limits<int>::max();
        if(j == res[0].size() - 2){
            temp.push_back(0);
        }else{
            temp.push_back(a);
        }
    }
    res.push_back(temp);
    
    for(int r = rows; r >= 0; r--){
        for(int c = columns; c >= 0; c--){
            res[r][c] = grid[r][c] + min(res[r+1][c], res[r][c+1]);
        }
    }

    return res[0][0];
}

// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minPathSumII(int n, int m, vector<vector<int>> &matrix) {
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; // Include the minimum path sum from above (previous row)
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last column
    return prev[m - 1];
}

int main(){
    vector<vector<int>> mat = {{1,3,1},{1,5,1},{4,2,1}};
    // cout<<minPathSumI(mat);
    cout<<minPathSumII(mat.size(), mat[0].size(), mat);
}