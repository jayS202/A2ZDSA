// Problem Statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

// Optimal - Merge Sort Linked List 
// TC - O(log N * (N + N/2)), SC - O(1)
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

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* TortoiseAndHare(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* h1, Node* h2){
    Node* dummyHead = new Node(-1);
    Node* t1 = h1;
    Node* t2 = h2;
    Node* temp = dummyHead;
    while(t1!=NULL && t2!=NULL){
        if(t1->data <= t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1){
        temp->next = t1;
    }else{
        temp->next = t2;
    }
    return dummyHead->next;
}

Node* sortLL(Node* head){
    if(head==NULL || head->next == NULL)return head;
    
    Node* middle = TortoiseAndHare(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL;
    
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    
    return merge(leftHead,rightHead);
}

int main()
{
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
