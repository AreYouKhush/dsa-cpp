#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr,int books, int students, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for(int i = 0; i < books; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount > students){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int bookAllocation(vector<int> &arr, int books, int students){
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(start < end){
        int mid = start + (end - start)/2;
        if(isPossible(arr, books, students, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {10,20,30,40};
    int students = 2;
    cout<<bookAllocation(vec, vec.size(), students);
}