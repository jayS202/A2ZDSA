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

// Approach:
// We use recursive backtracking to explore all possible combinations of opening '(' and closing ')' parentheses, while ensuring the sequence remains valid at every step.
// 🔧 Key Constraints
// - You can only add an opening bracket '(' if the number of opening brackets used so far is less than n.
// - You can only add a closing bracket ')' if the number of closing brackets used so far is less than the number of opening brackets used.

// 🪜 Step-by-Step Logic
// - Base Case: If open == n and close == n, we have a valid combination. Print or store res.
// - Recursive Case:
// - If open < n: Add '(' and recurse with open + 1.
// - If close < open: Add ')' and recurse with close + 1.
// ✅ Validity Guarantee
// By ensuring close < open, we prevent invalid sequences like ())( or (())).

#include<bits/stdc++.h>
using namespace std;

void generate_parenthesis(string res, int n, int open, int close){
    if(open==n && close==n){
        cout<<res<<'\n';
        return;
    }
    
    // take '('
    if(open<n){
        generate_parenthesis(res+'(', n, open+1, close);
    }
    
    // take ')'
    if(close<open){
        generate_parenthesis(res+')', n, open, close+1);   
    }
}

void generateAllParenthesis(int n){
    string res="";
    int open = 0;
    int close = 0;
    generate_parenthesis(res, n, open, close);
}

int main(){
    int n = 3;
    generateAllParenthesis(n);
    return 0;
}

