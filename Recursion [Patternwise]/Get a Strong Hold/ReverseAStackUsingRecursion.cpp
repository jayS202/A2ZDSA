// Problem Statement: Reverse a Stack using recursion.

// TC - O(N^2), O(1) 
#include<bits/stdc++.h>
using namespace std;

void putTopAtBottom(stack<int> &s, int topElement){
    if(s.empty()){
        s.push(topElement);
        return;
    }
    
    int temp = s.top();
    s.pop();
    putTopAtBottom(s, topElement);
    
    s.push(temp);
}

void reverseAStack(stack<int> &s){
    //Base case
    if(s.empty()){
        return;
    }
    
    // Hypothesis
    int topElement = s.top();
    s.pop();
    reverseAStack(s);
    
    putTopAtBottom(s, topElement);
}

void printStack(stack<int> &s){
    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    reverseAStack(s);
    
    cout<<"After Reversing: "<<"\n";
    printStack(s);
    return 0;
}
