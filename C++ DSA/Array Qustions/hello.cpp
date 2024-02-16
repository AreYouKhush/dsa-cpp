#include <iostream>

using namespace std;

int main(){
    int n = 5;
    // cout<<"Enter the number of lines: ";
    // cin>>n;

    for(int i = 0; i < n; i++){
        int num = n-i;
        int num1 = 1;
        for(int j = 0; j < n-i; j++, num1++){
            cout<<num1;
        }

        for(int k = 0; k < i; k++){
            cout<<"*";
        }

        for(int l = 0; l < i; l++){
            cout<<"*";
        }

        for(int m = n; m > 0+i; m--, num--){
            cout<<num;
        }

        cout<<endl;
    }
    return 0;
}