// Problem Statement - Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

// Brute Force
// TC - O(N+N/2) SC-O(1)
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

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int FindMiddle(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    int mid = (cnt/2)+1;
    int pos = 0;
    Node* current = head;
    while(current){
        mid = mid-1;
        if(mid == 0)break;
        current=current->next;
    }
    return current->data;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertArrToDLL(arr);
    print(head);
    cout<<endl;
    cout<<FindMiddle(head);
    return 0;
}


// Tortoise Hare Algorithm

// TC - O(N) SC - O(1)
// Method 1
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

Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int TortoiseHare(Node* head){
    Node* move = head;
    Node* temp = head;
    while(temp){
        move = move->next;
        temp=temp->next->next;
        if(temp == NULL||temp->next == NULL){
            return move->data;
        }
    }
    return move->data;
}


int main()
{
    vector<int> arr = {4,5,6,2,8,9,1};
    Node* head = convertArrToDLL(arr);
    print(head);
    cout<<endl;
    int data = TortoiseHare(head);
    cout<<data<<endl;
    return 0;
}

// Method 2
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

Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int TortoiseHare(Node* head){
    Node* move = head;
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        move = move->next;
        temp=temp->next->next;
        if(temp == NULL||temp->next == NULL){
            return move->data;
        }
    }
    return move->data;
} 


int main()
{
    vector<int> arr = {4,5,6,2,8,9,1};
    Node* head = convertArrToDLL(arr);
    print(head);
    cout<<endl;
    int data = TortoiseHare(head);
    cout<<data<<endl;
    return 0;
}

