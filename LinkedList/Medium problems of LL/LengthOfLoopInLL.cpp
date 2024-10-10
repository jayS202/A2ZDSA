// Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list; if not present, return 0.

// Brute Force
// TC - O(N) SC - O(N)
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


int lengthOfLoop(Node* head) {
    int timer = 1;
    Node* temp = head;
    unordered_map<Node*, int> mpp;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return timer - mpp[temp];
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}


int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}


// Optimal 
// TC - O(N) SC - O(1)
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

int countdiff(Node* slow, Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow!=fast){
        count++;
        fast = fast->next;
    }
    return count;
}

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast){
            return countdiff(slow, fast);
        }
    }
    return 0;
}


int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}


