// Problem Statement: Remove Duplicates from sorted DLL.

// TC - O(N) SC - O(1)
#include<bits/stdc++.h>
using namespace std;
 
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1,Node* next1,Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};

// Convert Array to doubly Linked List
Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

// Traverse through DLL
void Traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* RemoveDuplicatesSortedFromDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode = temp->next;
        while(nextNode!=NULL && temp->data == nextNode->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        
        temp->next = nextNode;
        if(nextNode)nextNode->prev=temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,1,1,3,4,5,5};
    Node* head = convertArrToDLL(arr);
    Traverse(head);
    cout<<endl;
    Node* h1 = RemoveDuplicatesSortedFromDLL(head);
    Traverse(h1);
    return 0;

}
