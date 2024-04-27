#include<bits/stdc++.h>
using namespace std;

void printName(int i, int n) {
    if(i >= n) return;
    cout<<"Khushal!\n";
    printName(i+1, n);
}

void printNum(int n) {
    if(n <= 0) return;
    cout<<n<<" ";
    printNum(n-1);
    cout<<n<<" ";
}

//Parameterized way
void sumOfNnums(int n, int& sum) {
    if(n <= 0){
        cout<<"Inside base case: "<<sum<<"\n";
        return;
    }
    sum += n;
    sumOfNnums(n-1, sum);
}

//Functional way
int sumOfNnumsRet(int n) {
    if(n == 0) return 0;
    return n + sumOfNnumsRet(n-1);
}

int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int main() {
    int n;
    cin>>n;
    printName(0, n);
    cout<<"\n";
    printNum(n);
    cout<<"\n\n";
    int sum = 0;
    cout<<"Parameterized way:\n";
    sumOfNnums(n, sum);
    cout<<"Referenced variable: "<<sum<<"\n\n";
    cout<<"Functional way: "<<sumOfNnumsRet(n)<<"\n\n";
    cout<<"Factorial of "<<n<<": "<<factorial(n)<<"\n\n";
}