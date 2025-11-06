// Problem Statement: You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.


#include<bits/stdc++.h>
using namespace std;

string PrefixToPostfix(string s){
    stack<string> st;
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1, s[i]));
        }else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string op3 = op1+op2+string(1,s[i]);
            st.push(op3);
        }
    }
    return st.top();
}

int main(){
    string s = "*-ABC";
    string res = PrefixToPostfix(s);
    cout<<res<<"\n";
    return 0;
}
