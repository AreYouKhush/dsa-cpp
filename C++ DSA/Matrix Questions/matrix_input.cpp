#include<bits/stdc++.h>
using namespace std;

int main(){
    int X = 0;
    int Y = 0;
    cout<<"Enter number of rows: ";
    cin>>X;
    cout<<"Enter number of columns: ";
    cin>>Y; 
    int matrix[X][Y];
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}