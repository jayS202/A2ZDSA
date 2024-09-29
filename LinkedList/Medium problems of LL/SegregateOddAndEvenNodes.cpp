// Problem Statement : Segregate even and odd nodes in LinkedList

// Given a LinkedList of integers. Modify the LinkedList in such a way that in Modified LinkedList all the even numbers appear before all the odd numbers in LinkedList.

// Also, note that the order of even and odd numbers should remain the same. 

// TC - O(N) SC - O(1)
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

Node* SegregatetoOddEven(Node* head){
   Node* evenLL = new Node(-1);
   Node* evenStart = evenLL;
   Node* oddLL = new Node(-1);
   Node* oddStart = oddLL;
   Node* temp = head;
   while(temp){
       if(temp->data & 1){
           Node* newOdd = new Node(temp->data);
           oddLL->next = newOdd;
           oddLL = oddLL->next;
       }else{
           Node* newEven = new Node(temp->data);
           evenLL->next = newEven;
           evenLL = evenLL->next;
       }
       temp = temp->next;
   }
   evenLL->next = oddStart->next;
   oddLL->next = nullptr;
   return evenStart->next;
}

int main()
{
    vector<int> l1 = {1,2,3,4,5,6};
    Node* h1 = convertToLL(l1);
    Traverse(h1);
    cout<<endl;
    Node* h2 = SegregatetoOddEven(h1);
    Traverse(h2);
    return 0;
}
