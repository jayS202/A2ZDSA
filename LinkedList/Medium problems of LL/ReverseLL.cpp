// Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->back = mover;
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

// Brute - Using stack 
// TC - O(2N) SC - O(N)
Node* reverseLL(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    
    Node* temp1 = head;
    while(temp1){
        temp1->data = st.top();
        st.pop();
        temp1 = temp1->next;
    }
    return head;
}

// Optimal Approach 1 - interchanging the links
// TC - O(N) SC - O(1)
Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* front = NULL;
    while(current!=NULL){
        front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
    return prev;
}

// Optimal Approach 2 - Recursion
// TC - O(N) SC - O(1)
Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newNode = reverseLL(head->next);
    Node* front = head -> next;
    front->next = head;
    head->next = NULL;
    return newNode;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    Node* head=convertArrToDLL(arr);
    print(head);
    cout<<endl;
    Node* head1 = reverseLL(head);
    print(head1);
    return 0;
}
