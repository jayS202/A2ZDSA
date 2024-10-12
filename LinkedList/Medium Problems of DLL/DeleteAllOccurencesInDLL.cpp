// Problem Statement - Delete all occurencess of Key in DLL.

// TC - O(N), SC - O(1)
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

Node* DeleteAllOccurences(Node* head, int key){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            if(temp==head){
                head = temp->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            
            if(nextNode!=NULL) nextNode->prev = prevNode;
            if(prevNode!=NULL) prevNode->next = nextNode;
            
            delete temp;
            temp = nextNode;
        }else{
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    vector<int> arr = {10,4,10,10,6,10};
    Node* head = convertArrToDLL(arr);
    Traverse(head);
    int key = 10;
    cout<<endl;
    Node* h1 = DeleteAllOccurences(head, key);
    Traverse(h1);
    return 0;

}
