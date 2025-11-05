#include<bits/stdc++.h>
using namespace std;

string reverseStr(string res){
    reverse(res.begin(), res.end());
    for (char &ch : res) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    return res;
}

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

string InfixToPrefix(string str){
    string ans = "";
    stack<char> st;
    int i = 0;
    
    // reverseStr(s.begin(),s.end());
    string s = reverseStr(str);

    while(i<s.size()){
        // Operands
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){ // isalnum(s[i])
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
            if(s[i] == '^'){
                while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            while(!st.empty() && precedence(s[i])<precedence(st.top())){
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
    
    // reverseStr(ans.begin(), ans.end());
    string result = reverseStr(ans);
    return result;
}

int main(){
    string s;
    cin>>s;
    string res = InfixToPrefix(s);
    cout<<res;
    return 0;
}
