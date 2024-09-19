#include<bits/stdc++.h>
using namespace std;
 
class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1,Node* next1,Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

// Convert Array to doubly Linked List
Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->back = mover;
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
 
// Insert At Head
Node* InsertAtHead(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
   
    Node* newNode = new Node(val);
    newNode->next = head;
    head->back = newNode;
    return newNode;
}

// Insert At Tail
Node* InsertAtTail(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->back = temp;
    return head;
}

// Insert at given position
Node* InsertAtPos(Node* head, int val, int pos){
    if(head==NULL){
        return new Node(val);
    }
    
    Node* temp = head;
    int cnt = 0;
    
    Node* newNode = new Node(val);
    
    while(temp->next!=NULL){
        cnt++;
        if(cnt == pos)break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(front==nullptr){
        return InsertAtTail(head,val);
    }
    
    if(prev==nullptr){
        return InsertAtHead(head, val);
    }
    
    prev->next = newNode;
    newNode->back = prev;
    
    newNode->next = temp;
    temp->back = newNode;
    
    return head;
    
} 


int main()
{
    vector<int> arr = {3,5,6,8,7};
    Node* head = convertArrToDLL(arr);
    Traverse(head);
    cout<<endl;
    Node* head1 = InsertAtHead(head, 4);
    Traverse(head1);
    cout<<endl;
    Node* head2 = InsertAtTail(head, 9);
    Traverse(head2);
    cout<<endl;
    Node* head3 = InsertAtPos(head, 4, 2);
    Traverse(head3);
    return 0;

}
