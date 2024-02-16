#include <iostream>
using namespace std;

int productSum(int num){
    int product = 1, sum = 0, diff;

    while(num != 0){
        int rem = num%10;
        sum += rem;
        product *= rem;
        num /= 10;
    }
    diff = product - sum;
    return diff;
}

int main(){
    int n;
    cout<<"Enter an interger: ";
    cin>>n;
    int ans = productSum(n);
    cout<<"The Subtraction of the Product and Sum of the digits of the given Integer = "<<ans;
    return 0;
}