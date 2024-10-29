// Problem Statement: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<string> &ans, string str, int open, int close, int n){
    if(str.length()==n * 2){
        ans.push_back(str);
        return;
    }
    if(open<n){
        backtrack(ans, str+'(', open+1, close, n);
    }
    if(close<open){
        backtrack(ans, str+')', open, close+1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(ans, "", 0, 0, n);
    return ans;
}

int main()
{
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}
