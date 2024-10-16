// Problem Statement: Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.

// TC - O(2N), SC - O(1)
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

Node* findKthNode(Node* temp, int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* ReverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* ReverseLLAtGivenKNodes(Node* head, int k){
    Node* temp = head;
    Node* prevNode = NULL;
    while(temp!=NULL){
        Node* KthNode = findKthNode(temp, k);
        if(KthNode==NULL){
            if(prevNode)prevNode->next = temp;
            break;
        }
        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        ReverseLL(temp);
        if(temp==head){
            head=KthNode;
        }else{
            prevNode->next = KthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = convertToLL(arr);
    Traverse(head);
    cout<<endl;
    int k = 3;
    Node* h1=ReverseLLAtGivenKNodes(head, k);
    Traverse(h1);
    return 0;
}
