#include<bits/stdc++.h>
using namespace std;

class StackUsingQueue {
    public:
        queue<int> q;
    
        void push(int n){
            int s = q.size();
            q.push(n);
            
            for(int i=0;i<s;i++){
                q.push(q.front());
                q.pop();
            }
        }  
        
        void pop(){
            if (q.empty()) {
                cout << "Stack Underflow - empty stack\n";
                return;
            }
            q.pop();
        }
        
        void size(){
            cout<<q.size()<<"\n";
            return;
        }
        
        void top(){
            if (q.empty()) {
                cout << "Stack is empty\n";
                return;
            }
            cout<<q.front()<<"\n";
            return;
        }
        
        void display(){
            if (q.empty()) {
                cout << "Stack is empty\n";
                return;
            }
            queue<int> temp = q;
            while(!temp.empty()){
                cout<<temp.front()<<" ";
                temp.pop();
            }
            cout<<'\n';
        }
};

int main(){
    StackUsingQueue que;
    
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.display();
    
    que.top();
    
    que.pop();
    que.display();
    
    que.pop();
    que.display();
    return 0;
}
