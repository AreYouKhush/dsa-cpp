#include<bits/stdc++.h>
using namespace std;

int usingExtraSpace(vector<int>& height) {
    vector<int> maxLeft(height.size(), 0);
    vector<int> maxRight(height.size(), 0);
    vector<int> minLR(height.size(), 0);
    for(int i = 1; i < height.size(); i++){
        maxLeft[i] = max(maxLeft[i-1], height[i-1]);
    }
    for(int i = height.size()-2; i >= 0; i--){
        maxRight[i] = max(maxRight[i+1], height[i+1]);
    }
    for(int i = 0; i < height.size(); i++){
        minLR[i] = min(maxLeft[i], maxRight[i]);
    }
    int water = 0;
    for(int i = 0; i < height.size(); i++){
        if(minLR[i] - height[i] < 0){
            continue;
        }
        water += (minLR[i] - height[i]);
    }
    return water;
}

int constantSpace(vector<int>& height){
    if(!height.size()) return 0;
    int l = 0, r = height.size() - 1;
    int maxL = height[l];
    int maxR = height[r];
    int water = 0;
    while(l < r){
        if(maxL > maxR){
            r--;
            maxR = max(maxR, height[r]);
            water += maxR - height[r];
        }else if(maxL <= maxR){
            l++;
            maxL = max(maxL, height[l]);
            water += maxL - height[l];
        }
    }
    return water;
}

int main(){
    vector<int> inp{9,8,2,6};
    // cout<<usingExtraSpace(inp)<<endl;
    cout<<constantSpace(inp);
}