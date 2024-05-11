#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp){
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++)
            if(task != last)
                maxi = max(maxi, points[day][task]);
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    int res = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last){
            res = points[day][task] + f(points, day - 1, task, dp);
            maxi = max(maxi, res);
        }
    }
    return dp[day][last] = maxi;
}
// TC - O(N*4) SC - O(N) + O(N*4)
int maximumPoints_memo(vector<vector<int>>& points, int n) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(points, n - 1, 3, dp);
}

// Tabulation
// TC - O(N*4*3) SC:- O(N*4)
int maximumPoints(vector<vector<int>>& points, int n) {
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(dp[0][2], points[0][2]);

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n-1][3];
}

int main() {
    vector<vector<int>> points = {{2,1,3},{3,4,6},{10,1,6},{8,3,7}};
    cout<<maximumPoints(points, points.size());
    return 0;
}