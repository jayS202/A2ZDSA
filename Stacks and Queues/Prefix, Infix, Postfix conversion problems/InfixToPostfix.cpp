// Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression.
// TC - O(N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch == '^'){
        return 3;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else if(ch == '+' || ch == '-'){
        return 1;
    }
    return -1;
}

string InfixToPostfix(string s){
    string ans = "";
    stack<char> st;
    int i = 0;
    while(i<s.size()){
        // Operands
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9')){ // isalnum(s[i])
            ans += s[i];
        }
        // (
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // )
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s = "(A+B)*(C+D)";
    string res = InfixToPostfix(s);
    cout<<res;
    return 0;
}
