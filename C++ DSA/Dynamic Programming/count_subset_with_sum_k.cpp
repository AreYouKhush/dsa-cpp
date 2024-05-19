#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int solve(int arr[], int n, int k, vector<vector<int>>&dp, int i) {
    if(i == n ) {
        if(k == 0) return dp[i][k] =  1; 
        else return 0;   
    } 

    if(dp[i][k] != -1) return dp[i][k] ;  

    if(k >= arr[i]) 
        return dp[i][k] = (solve(arr, n, k-arr[i], dp, i+1) + solve(arr, n, k, dp, i+1)) % MOD  ;  
    else 
        return dp[i][k] = solve(arr, n, k, dp, i+1) ;   
}

int perfectSum(int arr[], int n, int k){
    vector<vector<int>> dp(n+1 , vector<int> (k+1, -1)) ;     
    return solve(arr, n, k, dp, 0) ;  
}

int main() {
    int nums1[] = {2,2,2,2,3,4,5};
    int nums2[] = {1,2,3,4,5,2,2,1};
    int nums3[] = {5,2,3,10,6,8};
    cout<<perfectSum(nums1, 7, 4)<<endl;
    cout<<perfectSum(nums2, 8, 4)<<endl;
    cout<<perfectSum(nums3, 6, 10)<<endl;
    return 0;
}