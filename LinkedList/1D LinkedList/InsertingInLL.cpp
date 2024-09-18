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

// Insert At Head
Node* insertAtHead(Node* head, int val){
    Node* head1 = new Node(val, head);
    return head1;
}

// Insert At Tail
Node* insertAtTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at the given position 
Node* insertAtPos(Node* head, int val, int pos){
    if(head == NULL){
        if(pos==1)return new Node(val);
    }
    
    if(pos == 1){
        Node* head1 = new Node(val);
        head1->next = head;
        return head1;
    }
    Node* prev = NULL;
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == pos){
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insert or Replace a given value
Node* insertOnValue(Node* head, int val, int onVal){
    
    if(head->data == onVal){
        Node* newNode = new Node(val);
        Node* temp = head->next;
        delete head;
        newNode->next = temp;
        return newNode;
    }
    
    Node* prev = NULL;
    Node* temp = head;
    while(temp){
        Node* newNode = new Node(val);
        if(temp->data == onVal){
            prev->next = newNode;
            newNode->next = temp->next;
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
    vector<int> arr = {3,5,1,4,7};
    Node* head = convertToLL(arr);
    Traverse(head);
    cout<<endl;
    Node* head1 = insertAtHead(head, 6);
    Traverse(head1);
    cout<<endl;
    Node* head2 = insertAtTail(head, 9);
    Traverse(head2);
    cout<<endl;
    Node* head3 = insertAtPos(head, 2, 4);
    Traverse(head3);
    cout<<endl;
    Node* head4 = insertOnValue(head, 8, 1);
    Traverse(head4);
    return 0;
}
