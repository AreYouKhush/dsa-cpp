#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int i = 0;
    int j = prices.size()-1;
    int maxProfit = 0;
    while(i < j){
        maxProfit = max(prices[j] - prices[i], maxProfit);
        if(prices[i] > prices[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxProfit;
}

int main(){
    vector<int> inp = {7,1,5,3,6,4};
    cout<<maxProfit(inp);
}