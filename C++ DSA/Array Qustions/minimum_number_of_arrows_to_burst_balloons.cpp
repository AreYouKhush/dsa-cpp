#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0]; 
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int arrows = 1;
    int end = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        } else {
            end = min(end, points[i][1]);
        }
    }
    return arrows;
}

int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    // vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    // vector<vector<int>> points = {{16,24},{10,19},{14,17},{49,60}};
    // vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    cout<<findMinArrowShots(points);
}