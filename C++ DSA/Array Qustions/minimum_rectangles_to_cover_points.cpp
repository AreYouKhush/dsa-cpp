#include<bits/stdc++.h>
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    if(w == 0) return points.size();
    int rectangles = 0;
    sort(points.begin(), points.end());
    int lower = points[0][0];
    for(auto it: points){
        if(it[0] - lower > w){
            rectangles++;
            lower = it[0];
        }
    }
    return rectangles;
}

// int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
//     vector <int> a;
//     for (auto &p: points){
//         a.emplace_back(p[0]);
//     }
//     sort(begin(a), end(a), less <>());

//     int ans = 0;
//     int l = -w - 1;
//     for (auto &r: a){
//         if (r - l > w){
//             ans++;
//             l = r;
//         }
//     }
//     return ans;
// }

int main(){
    // vector<vector<int>> points = {{2,1},{1,0},{1,4},{1,8},{3,5},{4,6}};
    vector<vector<int>> points = {{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}};

    int w = 2;
    cout<<minRectanglesToCoverPoints(points, w);
}