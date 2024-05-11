#include<bits/stdc++.h>
using namespace std;

// jump +1 or +2
// Bottom - Up
int frogjumpBU(int heights[], int n, int dp[]) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int left = frogjumpBU(heights, n - 1, dp) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if(n > 1){
        right = frogjumpBU(heights, n - 2, dp) + abs(heights[n] - heights[n - 2]);
    }

    return dp[n] = min(left, right);
}

//Top - down
int frogjumpTD(int heights[], int size) {
    int dp[size];
    for(int i = 0; i < size; i++) dp[i] = -1;

    dp[0] = 0;
    if(size > 0) dp[1] = abs(heights[1] - heights[0]);

    for(int i = 2; i < size; i++) {
        int c1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int c2 = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(c1, c2);
    }

    return dp[size - 1];
}

int main() {
    int heights[] = {30,10,60,10,60,50};
    int size = sizeof(heights)/sizeof(heights[0]);
    int dp[size];
    for(int i = 0; i < size; i++) {
        dp[i] = -1;
    }
    cout<<frogjumpBU(heights, size - 1, dp)<<endl;
    cout<<frogjumpTD(heights, size);
}