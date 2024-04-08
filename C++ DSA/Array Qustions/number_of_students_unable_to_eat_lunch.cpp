#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n=students.size();
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(students[i]);
    }
    int count=0;
    int i=0;
    while(q.size()>0 && count!=q.size()){
        if(q.front()==sandwiches[i]){
            q.pop();
            i++;
            count=0;
        }
        else{
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}

int main(){
    vector<int> students = {0,1,0,1,0,1,0,0,0,1,0};
    vector<int> sandwiches = {0,1,0,1,0,1,0,0,1,1,1};
    cout<<countStudents(students, sandwiches);
}