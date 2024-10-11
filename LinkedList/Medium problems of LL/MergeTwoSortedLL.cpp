// Problem Statement - GIven Two Sorted Linked lists. Merge them into a single sorted Linked List.

// Brute Force
// TC - O(N1)+O(N2)+O(N log N)+O(N) where N = N1+N2, SC - O(N)+O(N)
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    
    Node(int data1){
        data = data1;
        next = NULL;
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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low>=high)return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    
    merge(arr, low, mid, high);
}



Node* mergeTwoLL(Node* h1, Node* h2){
    vector<int> arr;
    Node* temp1 = h1;
    while(temp1!=NULL){
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    
    Node* temp2 = h2;
    while(temp2!=NULL){
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
    
    mergeSort(arr, 0, arr.size()-1);
    
    Node* head = convertArrToLL(arr);
    return head;
}

int main()
{
    vector<int> arr1 = {2,4,8,10};
    vector<int> arr2 = {1,3,3,6,11,14};
    Node* h1 = convertArrToLL(arr1);
    Node* h2 = convertArrToLL(arr2);
    Traverse(h1);
    cout<<"\n";
    Traverse(h2);
    Node* h3 = mergeTwoLL(h1, h2);
    cout<<"\n";
    Traverse(h3);
    return 0;
}
