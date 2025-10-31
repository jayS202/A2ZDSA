// This is the implementation of Queues using Stack.
// Version 1: Costly push
// It takes TC of O(2N) for the implementation.
#include<bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    public:
        stack<int> s1, s2;
        void push(int n){
            if(s1.empty()){
                s1.push(n);
                return;
            }
            
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            
            s1.push(n);
            
            while(s2.size()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        void pop(){
            if(s1.empty()){
                cout<<"Queue is empty!"<<'\n';
                return;
            }
            s1.pop();
        }
        
        void peek(){
            if(s1.empty()){
                cout<<"Queue is empty!"<<'\n';
                return;
            }
            cout<<s1.top()<<"\n";
            return;
        }
        
        void size(){
            cout<<s1.size()<<"\n";
            return;
        }
        
        void display(){
            stack<int> temp = s1;
            while(!temp.empty()){
                cout<<temp.top()<<" ";
                temp.pop();
            }
            cout<<'\n';
        }
};


int main(){
    QueueUsingStack que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.display();
    
    que.pop();
    que.display();
    
    que.pop();
    que.display();
    
    que.peek();
    que.size();
    
    return 0;
}

// Version 2: Costly pop
// It takes TC of O(N) for the implementation.
#include<bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    public:
        stack<int> s1, s2;
        void push(int n){
            s1.push(n);
        }
        
        void pop(){
            if(s1.empty() && s2.empty()){
                cout << "Queue is empty!\n";
                return;
            }

            if(s2.empty())
                while(s1.size()) s2.push(s1.top()), s1.pop();
            s2.pop();
        }
        
        void peek(){
            if(s1.empty() && s2.empty()){
                cout << "Queue is empty!\n";
                return;
            }

            if(s2.empty())
                while(s1.size()) s2.push(s1.top()), s1.pop();
            cout<<s2.top()<<'\n';
            return;
        }
        
        void size(){
            cout<<s1.size()+s2.size()<<"\n";
            return;
        }
        
        void display(){
            if(s1.empty() && s2.empty()){
                cout << "Queue is empty!\n";
                return;
            }
        
            // Transfer all to s2 to maintain correct order
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        
            stack<int> temp = s2;
            vector<int> elems;
            while(!temp.empty()){
                elems.push_back(temp.top());
                temp.pop();
            }
           // reverse(elems.begin(), elems.end()); // to print front → rear
            for(int x : elems) cout << x << " ";
            cout << "\n";
        }
};

int main(){
    QueueUsingStack que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.display();
    
    que.pop();
    que.display();
    
    que.pop();
    que.display();
    
    que.peek();
    que.size();
    return 0;
}
