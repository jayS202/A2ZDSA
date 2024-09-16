#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    // In cpp they are not public by default
    public:
        // Constructor specifying data and the address
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        // Constructor specifying only data (New node is created with the nullptr)
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

// Convert Array to Linked List
Node* convertArrtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;// mover = temp;
    }
    return head;
}

// Traversing the Linked List
void Traverse(Node* head){
  // Never temper the value of head. 
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Finding the length of the Linked List
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Searching an element in the Linked List
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> arr = {5,4,8,2,1};
    Node* head = convertArrtoLL(arr);
    Traverse(head);
    cout<<lengthOfLL(head);
    cout<<checkIfPresent(head, 7);
    return 0;
}
