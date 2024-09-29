// Problem Statement : Segregate even and odd Index nodes in LinkedList

// Given a LinkedList of integers. Modify the LinkedList in such a way that in Modified LinkedList all the odd index nodes appear before all the even index nodes in LinkedList.

// Brute Force Solution
// TC - O(2N) SC - O(N)
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

Node* oddAndEven(Node* head){
    vector<int> arr;
    Node* oddInd = head;
    Node* evenInd = head->next;
    while(oddInd!=NULL && oddInd->next!=NULL){
        arr.push_back(oddInd->data);
        oddInd = oddInd->next->next;
    }
    if(oddInd){
        arr.push_back(oddInd->data);
    }
    while(evenInd!=NULL && evenInd->next!=NULL){
        arr.push_back(evenInd->data);
        evenInd = evenInd->next->next;
    }
    if(evenInd){
        arr.push_back(evenInd->data);
    }
    
    Node* temp = head;
    int i = 0;
    while(i<arr.size()){
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
    return head;
}


int main()
{
    vector<int> l1 = {1,2,3,4,5,6};
    Node* h1 = convertToLL(l1);
    Traverse(h1);
    cout<<endl;
    Node* h2 = oddAndEven(h1);
    Traverse(h2);
    return 0;
}

// Optimal Solution
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

Node* oddAndEven(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* oddInd = head;
    Node* evenInd = head->next;
    Node* evenNode = head->next;
    while(evenInd!=NULL && evenInd->next!=NULL){
        oddInd->next = oddInd->next->next;
        evenInd->next = evenInd->next->next;
        
        oddInd = oddInd->next;
        evenInd = evenInd->next;
    }
    oddInd->next = evenNode;
    return head;
}

int main()
{
    vector<int> l1 = {1,2,3,4,5,6};
    Node* h1 = convertToLL(l1);
    Traverse(h1);
    cout<<endl;
    Node* h2 = oddAndEven(h1);
    Traverse(h2);
    return 0;
}

