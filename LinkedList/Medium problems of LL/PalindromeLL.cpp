// Brute Force
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

Node* convertArrToLL(vector<int> &arr){
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

bool isPallindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(temp){
        if(temp->data != st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

int main(){
    vector<int> arr = {1,2,3,3,2,1};
    Node* h1 = convertArrToLL(arr);
    Traverse(h1);
    cout<<endl;
    bool res = isPallindrome(h1);
    (res)?cout<<"Linked List is pallindrome":cout<<"Linked List is not pallindrome";
    return 0;
}

// Optimal 
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

Node* convertArrToLL(vector<int> &arr){
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

Node* reverseLL(Node* head){
    if(head==NULL || head->next == NULL)return head;
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

bool isPallindrome(Node* head){
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL){
        
        if(first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

int main(){
    vector<int> arr = {1,2,3,3,2,1};
    Node* h1 = convertArrToLL(arr);
    Traverse(h1);
    cout<<endl;
    bool res = isPallindrome(h1);
    (res)?cout<<"Linked List is pallindrome":cout<<"Linked List is not pallindrome";
    return 0;
}
