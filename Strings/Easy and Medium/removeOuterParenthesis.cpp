// Problem Statement: A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

// TC - O(N) SC - O(1)

#include<bits/stdc++.h>
using namespace std;

string removeOuterParenthesis(string str){
    int cnt = 0;
    int n = str.size();
    string temp = "";
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            cnt++;
            if(cnt>1){
                temp = temp + '(';
            }
        }else{
            cnt--;
            if(cnt!=0){
                temp = temp + ')';
            }
        }
    }
    return temp;
}

int main()
{
    string s = "(()())(())(()(()))";
    string res = removeOuterParenthesis(s);
    cout<<res<<"\n";
    return 0;
}
