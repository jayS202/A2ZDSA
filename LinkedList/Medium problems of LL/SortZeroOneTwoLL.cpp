// Problem Statement: Sort the Zero's, One's and Two's in the Linked List.

//Brute Force
// TC - O(2N) SC - O(1)
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

Node* sortZeroOneTwo(Node* head){
    int cnt0=0, cnt1=0, cnt2=0;
    Node* temp = head;
    while(temp){
        if(temp->data==0){
            cnt0++;
        }else if(temp->data==1){
            cnt1++;
        }else{
            cnt2++;
        }
        temp = temp->next; 
    }
    temp = head;
    while(temp){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }else if(cnt1){
            temp->data = 1;
            cnt1--;
        }else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    
    return head;
}

int main()
{
    vector<int> l1 = {1,0,2,1,1,0,2,0,2};
    Node* h1 = convertToLL(l1);
    Traverse(h1);
    cout<<endl;
    Node* h2 = sortZeroOneTwo(h1);
    Traverse(h2);
    return 0;
}

// Optimal Solution
// TC - O(N), SC - O(1)
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

Node* sortZeroOneTwo(Node* head){
    Node* ZeroLL = new Node(-1); Node* zero = ZeroLL;
    Node* OneLL = new Node(-1); Node* one = OneLL; 
    Node* TwoLL = new Node(-1); Node* two = TwoLL;
    Node* temp = head;
    while(temp){
        if(temp->data==0){
            zero->next = temp;
            zero = temp;
        }else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (OneLL->next!=NULL)?OneLL->next:TwoLL->next;
    one->next = TwoLL->next;
    two->next = nullptr;
    return ZeroLL->next;
}

int main()
{
    vector<int> l1 = {1,0,2,1,1,0,2,0,2};
    Node* h1 = convertToLL(l1);
    Traverse(h1);
    cout<<endl;
    Node* h2 = sortZeroOneTwo(h1);
    Traverse(h2);
    return 0;
}
