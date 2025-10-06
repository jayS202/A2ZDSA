// Problem Statement - Sort a stack using recursion.

// TC - O(N^2), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

void sortRec(stack<int> &s, int topElement){
    if(s.empty() || topElement > s.top()){
        s.push(topElement);
        return;
    }
    
    int temp = s.top();
    s.pop();
    sortRec(s, topElement);
    
    s.push(temp);
}

void sortAStack(stack<int> &s){
    //Base case
    if(s.empty()){
        return;
    }
    
    // Hypothesis
    int topElement = s.top();
    s.pop();
    sortAStack(s);
    
    sortRec(s, topElement);
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
    s.push(10);
    s.push(5);
    s.push(30);
    s.push(15);
    s.push(20);
    
    sortAStack(s);
    
    cout<<"After sorting: "<<"\n";
    printStack(s);
    return 0;
}
