// Problem Statement: You are tasked with implementing a function to find all pairs of nodes in a doubly linked list that sum up to a specified key value.

// Brute Force
// TC - O(N^2) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1,Node* next1,Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};

// Convert Array to doubly Linked List
Node* convertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

// Traverse through DLL
void Traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

vector<pair<int,int>> FindPairsWithGivenSum(Node* head, int key){
    Node* temp = head;
    vector<pair<int,int>> res;
    while(temp!=NULL){
        Node* mover = temp->next;
        while(mover!=NULL && (temp->data + mover->data) <=key){
            if((temp->data + mover->data) == key){
                res.push_back({temp->data,mover->data});
            }
            mover = mover->next;
        }
        temp = temp->next;
    }
    return res;
}

int main()
{
    vector<int> arr = {1,2,3,4,9};
    Node* head = convertArrToDLL(arr);
    Traverse(head);
    int key = 5;
    cout<<endl;
    vector<pair<int,int>> res = FindPairsWithGivenSum(head, key);
    for(auto it: res){
        cout<<it.first<<" : "<<it.second<<"\n";
    }
    return 0;
}
