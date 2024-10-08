// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// Brute Force
// TC - O(N1*log n)+O(N3*log n) SC - O(N)
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};
//utility function to insert node at the end of the linked list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
    node* temp = head1;
    unordered_map<node*,int> mpp;
    while(temp!=NULL){
        mpp[temp]=1;
        temp=temp->next;
    }
    
    temp = head2;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//utility function to print linked list created
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}


int main()
{
    // creation of both lists 
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}


// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// Better
// TC - O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2)) SC - O(1)
// Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};
//utility function to insert node at the end of the linked list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

int getDiffernce(node* head1, node* head2){
    node* temp = head1;
    int len1 = 0, len2 = 0;
    while(head1!=NULL || head2!=NULL){
        if(head1!=NULL){
            len1++;
            head1=head1->next;
        }
        if(head2!=NULL){
            len2++;
            head2 = head2->next;
        }
    }
    return len1-len2;
}

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
    int diff = getDiffernce(head1,head2);
    if(diff<0) 
        while(diff++ != 0)head2 = head2->next;
    else 
        while(diff-- != 0)head1 = head1->next;
        
    while(head1!=NULL){
        if(head1 == head2)return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

//utility function to print linked list created
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}


int main()
{
    // creation of both lists 
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}


// Optimal Approach
// TC - O(N1+N2) SC - O(1)
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};
//utility function to insert node at the end of the linked list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
    if(head1==NULL || head2==NULL)return NULL;
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        
        if(temp1==temp2)return temp1;
        
        if(temp1==NULL)temp1 = head2;
        if(temp2==NULL)temp2 = head1;
    }
    return temp1;
}

//utility function to print linked list created
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}


int main()
{
    // creation of both lists 
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}
