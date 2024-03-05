#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> changeInHand(2, 0);
        int i = 0;
        for(i = 0; i<bills.size(); i++){
            if(bills[i] == 5){
                changeInHand[0]++;
            }else if(bills[i] == 10){
                if(changeInHand[0] > 0){
                    changeInHand[1]++;
                    changeInHand[0]--;
                }else{
                    break;
                }
            }else if(bills[i] == 20){
                if(changeInHand[1] > 0 && changeInHand[0] > 0){
                    changeInHand[1]--;
                    changeInHand[0]--;
                }else if(changeInHand[0] >= 3){
                    changeInHand[0] -= 3;
                }else{
                    break;
                }
            }
        }
        return i == bills.size();
    }
};

int main(){
    Solution s1;
    vector<int> inp = {5,10,5,5,5,5,5,5,5,10,20,20,20,20};
    bool ans = s1.lemonadeChange(inp);
    cout<<ans;
}