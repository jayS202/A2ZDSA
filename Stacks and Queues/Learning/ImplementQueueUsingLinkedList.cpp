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

class QueueImpl{
    public:
        Node* start = NULL;
        Node* end = NULL;
        int size = 0;
    
        void push(int n){
            Node* temp = new Node(n);
            if(start == NULL){
                start = temp;
                end = temp;
            }else{
                end->next = temp;
                end = temp;   
            }
            size++;
        }
        
        void pop(){
            if(start == NULL){
                cout<<"Queue Underflow - Queue is Empty"<<"\n";
                return;
            }
            Node* temp = start;
            start = start->next;
            delete temp;
            size--;
            if(start==NULL) end = NULL;
        }
        
        void top(){
            if(start == NULL){
                cout<<"Queue is empty."<<'\n';
                return;
            }
            cout<<start->data<<'\n';
            return;
        }
        
        void length(){
            cout<<size<<'\n';
            return;
        }
        
        void display(){
            Node* temp = start;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<'\n';
        }
};

int main(){
    QueueImpl que;
    que.push(7);
    que.push(3);
    que.push(4);
    que.push(10);
    que.display();
    
    que.pop();
    que.display();
    
    que.pop();
    que.display();
    
    que.top();
    
    que.length();
    return 0;
}
