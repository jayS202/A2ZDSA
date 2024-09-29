// Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

// BruteForce
// TC - O(N)+O(N-n) SC - O(1)
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

Node* removeNthNodefromBack(Node* head, int n){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    
    int res = cnt - n;
    if(cnt == n){
        Node* newNode = head->next;
        free(head);
        return newNode;
    }
    temp = head;
    while(temp!=NULL){
        res--;
        if(res == 0){
            break;
        }
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

int main()
{
    vector<int> l1 = {1,2,3,4,5};
    Node* h1 = convertToLL(l1);
    int n = 2;
    Traverse(h1);
    cout<<endl;
    Node* h2 = removeNthNodefromBack(h1, n);
    Traverse(h2);
    return 0;
}


// Optimal 
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

Node* removeNthNodefromBack(Node* head, int n){
    Node* fast = head;
    for(int i=1;i<=n;i++){
        fast = fast -> next;
    }
    if(fast == NULL){
        Node* newNode = head->next;
        free(head);
        return newNode;
    }
    Node* slow = head;
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}


int main()
{
    vector<int> l1 = {1,2,3,4,5};
    Node* h1 = convertToLL(l1);
    int n = 2;
    Traverse(h1);
    cout<<endl;
    Node* h2 = removeNthNodefromBack(h1, n);
    Traverse(h2);
    return 0;
}
