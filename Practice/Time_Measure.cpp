#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void fun1(){
    int n = 2000;
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == n-1 || j == 0 || j == n-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
}

int main()
{
    
    time_t start, end;
 
    time(&start);
 
    ios_base::sync_with_stdio(false);
    
    // fun();
    fun1();
 
    time(&end);
 
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
