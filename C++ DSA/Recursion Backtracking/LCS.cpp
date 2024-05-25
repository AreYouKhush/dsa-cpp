#include <bits/stdc++.h>
using namespace std;
 
int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if ((X[m - 1] == Y[n - 1]) && ((X[m-1] == 'a') || (X[m-1] == 'A') || (X[m-1] == 'e') || (X[m-1] == 'E') || (X[m-1] == 'i') || (X[m-1] == 'I') || (X[m-1] == 'o') || (X[m-1] == 'O') || (X[m-1] == 'u') || (X[m-1] == 'U')))
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1),
                   lcs(X, Y, m - 1, n));
}
 
int main()
{
    string S1 = "aekds";
    string S2 = "fjeac";
    int m = S1.size();
    int n = S2.size();
 
    cout << "Length of LCS is " << lcs(S1, S2, m, n);
 
    return 0;
}