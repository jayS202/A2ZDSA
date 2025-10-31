// Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Approach 1:
// Each time we push a new element, we compare it with the current minimum and record the smaller one alongside it. This way, the stack always remembers the minimum up to that point.
// TC - O(1), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        stack<pair<int,int>> st;
        
        void push(int n){
            if(st.empty()) st.push({n,n});
            else st.push({n, min(n, st.top().second)});
        }
        
        void pop(){
            if(st.empty()){
                cout << "Stack is empty!\n";
                return;
            }
            st.pop();
        }
        
        void top(){
            if(st.empty()){
                cout << "Stack is empty!\n";
                return -1; // or throw exception
            }
            cout<<st.top().first<<"\n";
            return;
        }
        
        void getMin(){
            if(st.empty()){
                cout << "Stack is empty!\n";
                return; // or throw exception
            }
            cout<<st.top().second<<"\n";
            return;
        }
};

int main(){
    Stack s;
    s.push(3);
    s.push(5);
    s.push(2);
    
    s.getMin();
    s.pop();
    
    s.top();
    s.getMin();
    return 0;
}
