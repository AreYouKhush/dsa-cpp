#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int> (n));
    int left = 0, right = matrix.size() - 1;
    int top = left, bottom = right;
    int num = 1;
    while(left <= right){
        for(int i = left; i <= right; i++){
            matrix[top][i] = num;
            num++;
        }
        if(bottom - top - 1 > 0){
            for(int i = top + 1; i < bottom; i++){
                matrix[i][right] = num;
                num++;
            }
        }
        if(right - left -1 > 0 || n%2 == 0){
            for(int i = right; i >= left; i--){
                matrix[bottom][i] = num;
                num++;
            }
        }
        if(bottom - top - 1 > 0){
            for(int i = bottom - 1; i > top; i--){
                matrix[i][left] = num;
                num++;
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return matrix;
}

int main(){
    int n = 4;
    vector<vector<int>> matrix = generateMatrix(2);
    for(auto it1: matrix){
        for(auto it2: it1){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}