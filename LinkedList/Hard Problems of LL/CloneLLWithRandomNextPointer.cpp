// Problem Statement: Given a linked list where every node in the linked list contains two pointers:

// ‘next’ which points to the next node in the list.
// ‘random’ which points to a random node in the list or ‘null’.
// Create a ‘deep copy’ of the given linked list and return it.


// Brute Force
// TC - O(2N), SC - O(N)+O(N)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class to represent
// elements in the linked list
class Node {
    public:
        int data;           
        Node *next;        
        Node *random;       
    
        Node() : data(0), next(nullptr), random(nullptr){}; 
        Node(int x) : data(x), next(nullptr), random(nullptr) {} 
      
        Node(int x, Node *nextNode, Node *randomNode) :
                data(x), next(nextNode), random(randomNode) {}  
};

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

Node* cloneLL(Node* head){
    Node* temp = head;
    unordered_map<Node*, Node*> mpp;
    while(temp!=NULL){
        Node* copyNode = new Node(temp->data);
        mpp[temp] = copyNode;
        temp = temp->next;
    }
    
    temp = head;
    while(temp!=NULL){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return head;
}

int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}

// Optimal 
// TC - O(3N), SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node* random;
        
    Node(){
        data = 0;
        next = nullptr;
        random = nullptr;
    }
        
    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
    }
    
    Node(int data1, Node* next1, Node* random1){
        data = data1;
        next = next1;
        random = random1;
    }
};

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

void cloneNodes(Node* head){
    Node* temp = head;
    Node* res = temp;
    while(temp!=NULL){
        Node* copyNode = new Node(temp->data);
        res = res->next;
        temp->next = copyNode;
        temp = temp->next;
        temp->next = res;
        temp = temp->next;
    }
}

void randomConnection(Node* head){
    Node* temp = head;
    Node* res = temp;
    while(temp!=NULL){
        res = temp->next;
        if(temp->random){
            res->random = temp->random->next;
        }else{
            res->random = nullptr;
        }
        res = res->next;
        temp = temp->next->next;
    }
}

Node* connectNext(Node* head){
    Node* temp = head;
    Node* dNode = new Node(-1);
    Node* res = dNode;
    while(temp!=NULL){
        Node* front = temp->next->next;
        res->next = temp->next;
        temp->next = front;
        res = res->next;
        temp = front;
    }
    return dNode->next;
}

Node* cloneLL(Node* head){
    cloneNodes(head);
    randomConnection(head);
    return connectNext(head);
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);
    
    cout<<"\n";
    
    Node* h1 = cloneLL(head);
    printClonedLinkedList(head);

    return 0;
}
