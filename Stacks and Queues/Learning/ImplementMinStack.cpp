// Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Approach 1:
// Each time we push a new element, we compare it with the current minimum and record the smaller one alongside it. This way, the stack always remembers the minimum up to that point.
// TC - O(1), SC - O(2N)
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

// Approach 2:
// TC - O(1), SC - O(N)
#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        stack<int> st;
        int mini = INT_MAX;

        void push(int n){
            if(st.empty()){
                mini = n;
                st.push(n);
            }
            else{
                if(n<mini){
                    int newVal = (2*n)-mini;
                    st.push(newVal);
                    mini = n;
                }else{
                    st.push(n);
                }   
            }
        }
        
        void pop(){
            if(st.empty()){
                cout<<"Stack is empty!"<<'\n';
                return;
            }
            int x = st.top();
            st.pop();
            if(x<mini){
                mini = (2*mini)-x;
            }
        }
        
        int top(){
            if(st.empty()){
                cout<<"Stack is empty"<<'\n';
                return -1;
            }
            int el = st.top();
            if(el<mini){
                return mini;
            }else{
                return el;
            }
        }
        
        int getMin(){
            if (st.empty()) {
                cout << "Stack is empty!" << '\n';
                return -1; // sentinel
            }

            return mini;
        }
};

int main(){
    Stack s;
    
    cout << "Current Min: " << s.getMin() << '\n';
    
    s.push(-2);
    s.push(0);
    s.push(-3);
    // s.push(2);

    cout << "Current Min: " << s.getMin() << '\n';
    cout << "Top: " << s.top() << '\n';           // 2

    s.pop();
    cout << "Current Min: " << s.getMin() << '\n'; // 3
    cout << "Top: " << s.top() << '\n';           // 7

    return 0;
}
