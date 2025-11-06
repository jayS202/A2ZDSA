// Problem Statement: You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.
// Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.

#include<bits/stdc++.h>
using namespace std;

string PrefixToInfix(string s){
    stack<string> st;
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1, s[i]));
        }else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string op3 = '('+op1+s[i]+op2+')';
            st.push(op3);
        }
    }
    return st.top();
}

int main(){
    string s = "*-A/BC-/AKL";
    string res = PrefixToInfix(s);
    cout<<res<<"\n";
    return 0;
}
