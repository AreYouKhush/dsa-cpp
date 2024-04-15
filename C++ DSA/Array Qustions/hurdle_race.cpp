#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> heights = {1,6,3,5,2};
    int initJump = 4;
    int potions = 0;
    int maxNum = 0;

    for(int i = 0; i < heights.size(); i++){
        maxNum = max(maxNum, heights[i]);
    }

    cout<<maxNum - initJump;
}