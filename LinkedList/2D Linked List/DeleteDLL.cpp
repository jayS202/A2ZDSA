#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1, Node* next1, Node* back1){
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

// Convert Arr to Doubly Linked list
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

// Traverse and print the elements
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Delete Head of Doubly Linked List
Node* DeleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
}

// Delete tail of Doubly Linked List
Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;   
    }
    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

// Delete Node At the given position of Doubly Linked List
Node* DeleteAtpos(Node* head, int pos){
    if(head==NULL)return NULL;
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos)break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev==NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return DeleteHead(head);
    }else if(front==NULL){
        return DeleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    delete temp;
    return head;
}

// Delete particular Node of Doubly Linked List
void DeleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    
    prev->next = front;
    front->back = prev;
    temp->back = temp->next = nullptr;
    free(temp);
}

int main()
{
    vector<int> arr = {3,5,6,8,7};
    Node* head = convertArrToDLL(arr);
    print(head);
    cout<<endl;
    Node* head1 = DeleteHead(head);
    print(head1);
    cout<<endl;
    Node* head2 = DeleteTail(head);
    print(head2);
    cout<<endl;
    Node* head3 = DeleteAtpos(head, 2);
    print(head3);
    cout<<endl;
    DeleteNode(head->next->next->next->next);
    print(head);
    return 0;
}
