// Problem Statement: A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

// TC - O(N) SC - O(1)
// Brute
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

// TC - O(N) SC - O(1)
//Optimal
#include<bits/stdc++.h>
using namespace std;

string removeOuterParenthesis(string str){
    int cnt = 0;
    int pos = 0;
    int n = str.size();
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            cnt++;
            if(cnt>1){
                str[pos++] = '(';
            }
        }else{
            cnt--;
            if(cnt!=0){
                str[pos++] = ')';
            }
        }
    }
    return str.substr(0,pos);
}

int main()
{
    string s = "(()())(())(()(()))";
    string res = removeOuterParenthesis(s);
    cout<<res<<"\n";
    return 0;
}
