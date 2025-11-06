// Problem Statement: You are given a valid postfix expression as a string, where:
// Operands are single lowercase English letters ('a' to 'z')
// Operators are binary: '+', '-', '*', '/'
// The expression contains no spaces and is guaranteed to be valid.

// Write a function to convert the postfix expression into a prefix expression, also as a string without spaces.

#include<bits/stdc++.h>
using namespace std;

string PostfixToPrefix(string s){
    stack<string> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1, s[i]));
        }else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string op3 = string(1,s[i])+op2+op1;
            st.push(op3);
        }
    }
    return st.top();
}

int main(){
    string s = "ABC/-AK/L-*";
    string res = PostfixToPrefix(s);
    cout<<res<<"\n";
    return 0;
}
