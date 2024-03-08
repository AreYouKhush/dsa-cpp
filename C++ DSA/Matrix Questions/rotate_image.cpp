#include<bits/stdc++.h>
using namespace std;

void rotateI(vector<vector<int>>& matrix) {
    int left = 0, right = matrix.size() - 1;
    while(left < right){
    for(int i = 0; i < right - left; i++){
            int top = left, bottom = right;
            swap(matrix[top][left+i], matrix[top+i][right]);
            swap(matrix[top][left+i], matrix[bottom][right-i]);
            swap(matrix[top][left+i], matrix[bottom-i][left]);
        }
        right--;
        left++;
    }
}

void rotateII(vector<vector<int>>& matrix) {
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;
    while(left < right){
        for(int i = 0; i < right - left; i++){
            top = left;
            bottom = right;
            int topLeft = matrix[top][left+i];
            matrix[top][left+i] = matrix[bottom-i][left];
            matrix[bottom-i][left] = matrix[bottom][right-i];
            matrix[bottom][right-i] = matrix[top+i][right];
            matrix[top+i][right] = topLeft;
        }
        left++;
        right--;
    }
}

void rotateIII(vector<vector<int>>& matrix) {
    int row = matrix.size();
    for(int i=0;i<row; i++){
        for(int j=0; j<=i;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<row;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int>> inp = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    cout<<"Before Rotation: "<<endl;
    for(auto it: inp){
        for(auto it1: it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    cout<<"After Rotation: "<<endl;
    rotateI(inp);
    for(auto it: inp){
        for(auto it1: it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}