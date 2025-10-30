#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        
        Node(int data1){
            data = data1;
            next = NULL;
        }
};

// Stack implementation using Linked List
class StackImpl{
    public:
        Node* top = NULL;
        int size = 0;
        
        void push(int n){
            Node* newNode = new Node(n);
            newNode->next = top;
            top = newNode;
            size = size+1;
        }
        
        void pop(){
            if(top == NULL){
                cout<<"Stack Underflow - empty Stack"<<'\n';
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
            size = size-1;
        }
        
        void peek(){
            if(top == NULL){
                cout<<"Stack is empty"<<"\n";
                return;
            }
            cout<<top->data<<"\n";
            return;
        }
        
        void length(){
            cout<<size<<"\n";
            return;
        }
        
        void display(){
            if(top == NULL){
                cout<<"Stack is empty"<<"\n";
                return;
            }
            Node* temp = top;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
};

int main(){
    StackImpl st;
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(9);
    
    st.display();
    
    st.pop();
    st.display();
    
    st.pop();
    st.display();
    
    st.peek();
    
    st.length();
    
    return 0;
}
