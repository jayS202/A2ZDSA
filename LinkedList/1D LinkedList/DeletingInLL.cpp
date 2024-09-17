#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
        
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertToLL(vector<int> arr){
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

// Delete At Head
Node* deleteAtHead(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete At Tail
Node* deleteAtTail(Node* head){
    if(head == NULL)return head;
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

// Delete At any position
Node* deleteAtpos(Node* head, int k){
    if(head==NULL)return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {3,5,2,7,1};
    Node* head = convertToLL(arr);
    Traverse(head);
    cout<<endl;
    Node* head1 = deleteAtpos(head,3);
    Traverse(head1);
    return 0;
}
