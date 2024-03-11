#include<bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int box = 0;
    sort(apple.begin(), apple.end());
    sort(capacity.begin(), capacity.end());
    int i = 0, j = capacity.size() - 1;
    int count = 0;
    while(i < apple.size() && j >= 0){
        cout<<count<<" "<<box<<" "<<apple[i]<<" "<<capacity[j]<<endl;
        if(count == 0){
            box++;
        }
        if(capacity[j] == apple[i]){
            j--;
            i++;
            count = 0;
        }else if(capacity[j] > apple[i]){
            capacity[j] -= apple[i];
            i++;
            count++;
        }else{
            j--;
            capacity[j] += capacity[j+1];
            count = 0;
        }
    }
    return box;
}

int main(){
    vector<int> apple = {3,5,7,6,2};
    vector<int> capacity = {10,10,10};
    cout<<minimumBoxes(apple, capacity);
}