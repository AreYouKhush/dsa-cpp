#include<iostream>
using namespace std;

int main(){
    int len = 0;
    cout<<"Enter height of the pyramid: ";
    cin>>len;
    for(int i = 0; i < len; i++){
        int j = 0;
        for(j = 0; j < len - i - 1; j++){
            cout<<" ";
        }
        for(int k = 0; k < len-j; k++){
            cout<< "* ";
        }
        cout<<endl;
    }
    for(int i = 0; i < len-1; i++){
        int j = 0;
        for(j = i; j >= 0; j--){
            cout<<" ";
        }
        for(int k = 0; k < len-i-1; k++){
            cout<< "* ";
        }
        cout<<endl;
    }
}