// Problem Statement: Add 1 to number in Linked list.
// Example 1: Input = 1 5 9 Output = 1 6 0
// Example 2: Input = 9 9 9 Output = 1 0 0 0

// Brute Force
// TC - O(3N), SC - O(1) 
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


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; 
        temp = temp->next; 
    }
    cout << endl;
}

Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    
    Node* newHead = reverseLL(head->next);
    
    Node* front = head->next;
    front->next = head;
    head->next = NULL; 
    return newHead;
}


Node* AddOne(Node* head){
    int carry = 1;
    Node* newHead = reverseLL(head);
    Node* temp = newHead;
    while(temp!=NULL){
        int total = temp->data + carry;
        if(total<10){
            temp->data = total;
            carry = 0;
            break;
        }else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry==1){
        Node* newNode = new Node(1);
        Node* head = reverseLL(newHead);
        newNode->next=head;
        return newNode;
    }
    Node* HeadOne = reverseLL(newHead);
    return HeadOne;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = AddOne(head);

    cout << "After Adding One: ";
    printLinkedList(head);

    return 0;
}

// Optimal
// TC - O(N) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void Traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int recursiveAddOne(Node* temp){
    if(temp == NULL)return 1;
    int carry= recursiveAddOne(temp->next);
    temp->data = (temp->data)+carry;
    if(temp->data<10){
        return 0;
    }
    
    temp->data = 0;
    return 1;
}

Node* addOneToLL(Node* head){
    int carry = recursiveAddOne(head);
    if(carry==1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr = {9,9,9};
    Node* h1 = convertArrToLL(arr);
    Traverse(h1);
    cout<<endl;
    Node* h2 = addOneToLL(h1);
    Traverse(h2);
    return 0;
}
