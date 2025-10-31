// Problem Statement: Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']', check if the input string is valid and return true if the string is balanced otherwise return false.
// Note: string str is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.

// Approach:
// 1. Traverse the string till last. Create an empty stack to track the opening/closing brackets.
// 2. While traversing:
// - If character is any open bracket. Push it to the stack.
// - If character is any closing bracket. check if the top element of the stack is the opening of the same order.
//   * same order, then continue.
//   * If not, return false.
// 3. After all the traversing. If the parantheses are balanced, The stack will be empty. 
// 4. In the end, Return it to show the boolean value.

// TC - O(N), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

bool checkForBalancedParanthesis(string str){
    stack<char> st;
    for(auto it: str){
        if(it == '(' || it == '[' || it == '{') st.push(it);
        else{
            if(st.size() == 0) return false;
            char ch = st.top();
            st.pop();
            if((it == '}' and ch == '{') or (it == ')' and ch == '(') or (it == ']' and ch == '[')) continue;
            else return false;
        }
    }
    return st.empty();
}

int main(){
    string str = "()[{}{}";
    bool res = checkForBalancedParanthesis(str);
    cout<< ((res)? "It is a balanced Paranthesis!": "It is not!");
    return 0;
}
