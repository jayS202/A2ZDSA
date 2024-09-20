// Problem Statement: Reverse the DLL

// TC - O(2N) SC - O(N)
// Using Stack
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

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL)return head;
    stack<int> st;
    Node* temp = head;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    
    Node* temp1 = head;
    while(temp1){
        temp1->data = st.top();
        st.pop();
        temp1 = temp1->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {4,5,6,7,8};
    Node* head=convertArrToDLL(arr);
    print(head);
    cout<<endl;
    Node* head1 = reverseDLL(head);
    print(head1);
    return 0;
}

// Optimzed Solution - Swapping the Next and Back Links
// TC - O(N) SC - O(1)
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

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL)return head;
    Node* last = NULL;
    Node* current = head;
    while(current){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}

int main()
{
    vector<int> arr = {4,5,6,7,8};
    Node* head=convertArrToDLL(arr);
    print(head);
    cout<<endl;
    Node* head1 = reverseDLL(head);
    print(head1);
    return 0;
}
