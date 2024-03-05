#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string S){
    string temp = "";
    int regular = 0;
    int square = 0;
    int curly = 0;
    int i;
    for(i = 0; i < S.size(); i++){
        if(S[i] == '('){
            regular++;
            temp += '(';
        }else if(S[i] == ')' && regular > 0 && temp[temp.size() - 1] != '[' && temp[temp.size() - 1] != '{'){
            regular--;
            temp += ')';
        }else if(S[i] == '{'){
            curly++;
            temp += '{';
        }else if(S[i] == '}' && curly > 0  && temp[temp.size() - 1] != '[' && temp[temp.size() - 1] != '('){
            curly--;
            temp += '}';
        }else if(S[i] == '['){
            square++;
            temp += '[';
        }else if(S[i] == ']' && square > 0 && temp[temp.size() - 1] != '(' && temp[temp.size() - 1] != '{'){
            square--;
            temp += ']';
        }else{
            break;
        }
    }
    return i == S.size() && regular == 0 && square == 0 && curly == 0;
}

int main(){
    string S = "[{}()]";
    cout<<isBalanced(S);
}