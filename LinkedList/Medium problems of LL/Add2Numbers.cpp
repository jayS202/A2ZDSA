// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// TC - O(max(m,n)) SC - O(max(m,n) where m is the size of l1 linked list and n is the size of l2 linked list
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

// Convert Array to LinkedList
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

// Traverse
void Traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* AddTwoNumbers(Node* h1, Node* h2){
    int carry = 0;
    Node* dummy = new Node(-1);
    Node* current = dummy;
    while((h1!=NULL||h2!=NULL)||carry){
        int sum = 0;
        if(h1!=NULL){
            sum += h1->data;
            h1 = h1->next;
        }
        if(h2!=NULL){
            sum += h2->data;
            h2 = h2->next;
        }
        
        sum += carry;
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        current->next = newNode;
        current = current->next;
    }
    return dummy->next;
}


int main()
{
    vector<int> l1 = {3,5};
    vector<int> l2 = {4,5,9,9};
    Node* h1 = convertToLL(l1);
    Node* h2 = convertToLL(l2);
    Traverse(h1);
    cout<<endl;
    Traverse(h2);
    cout<<endl;
    Node* head2 = AddTwoNumbers(h1,h2);
    Traverse(head2);
    return 0;
}
