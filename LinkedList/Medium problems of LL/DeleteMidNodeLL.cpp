// Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

// Brute Force
// TC - O(N + N/2) SC - O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;  
    Node* next;     

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


Node *deleteMiddle(Node *head) {
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    
    int mid = cnt/2;
    temp = head;
    while(temp!=NULL){
        mid--;
        if(mid==0){
            Node* middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }
        temp = temp->next;
    }
    return head;
}


void printLL(Node* head){
    
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    return 0;
}

// Optimal 
// TC - O(N/2) SC - O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;  
    Node* next;     

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


Node *deleteMiddle(Node *head) {
    Node* slow = head;
    Node* fast = head->next->next;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    
    return head;
}


void printLL(Node* head){
    
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    return 0;
}



