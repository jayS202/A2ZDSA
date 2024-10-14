// Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

// TC - O(2N), SC - O(1)
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* RotateLL(Node* head, int k){
    if(head==NULL || k==0)return head;
    
    Node* tail = head;
    int len = 1;
    while(tail->next!=NULL){
        len++;
        tail = tail->next;
    }
    k = k%len;
    if(k==0)return head;
    
    tail->next = head;
    
    Node* temp = head;
    for(int i=0;i<len-k-1;i++){
        temp = temp->next;
    }
    
    head = temp->next;
    temp->next = NULL;
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    Node* head=convertArrToDLL(arr);
    print(head);
    cout<<endl;
    int k = 3;
    Node* h1 = RotateLL(head, k);
    print(h1);
    return 0;
}
