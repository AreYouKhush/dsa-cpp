#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    if(rowIndex == 0) return {1};
    vector<int> prev = {1,1};
    for(int i = 2; i <= rowIndex; i++) {
        vector<int> current(i+1, 0);
        for(int j = 0; j < i+1; j++) {
            if(j == 0 || j == i) current[j] = 1;
            else{
                current[j] = prev[j-1] + prev[j];
            }
        }
        prev = current;
    }
    return prev;
}

int main() {
    int k = 7;
    vector<int> row = getRow(k); 
    for(int i = 0; i < row.size(); i++) {
        cout<<row[i]<<" ";
    }
    return 0;
}