// Problem Statement: Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// TC - O(N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

int maxNestDepth(string str){
    int cnt = 0;
    int maxDepth = 0;
    for(char ch: str){
        if(ch == '('){
            cnt++;
            maxDepth = max(maxDepth,cnt); 
        }
        else if(ch == ')') cnt--;
    }
    return maxDepth;
}

int main()
{
    string str = "()(())((()()))";
    int res = maxNestDepth(str);
    cout<<res;
    return 0;
}
