// Inserting at the Head
// Inserting at the tail

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

void traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Inserting at the head
Node* insertAtHead(Node* head, int val){
    Node* head1 = new Node(val, head);
    return head1;
}

// Inserting at the tail
Node* insertAtTail(Node* head, int val){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* tail = new Node(val);
    temp->next = tail;
    return head;
}

int main()
{
    vector<int> arr = {3,5,2,6,1};
    Node* head = convertToLL(arr);
    traverse(head);
    cout<<"\n";
    Node* head1 = insertAtHead(head, 9);
    traverse(head1);
    cout<<"\n";
    Node* head2 = insertAtTail(head1, 10);
    traverse(head2);
    return 0;
}
