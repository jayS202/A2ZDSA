// Problem Statement: You will be given multiple linked lists. You will need to merge all of them and return the head of the merged LL.

// Better
// TC - O(N*(k*((k+1))/2)),SC - O(1) 
Node* merge2LL(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1){
        temp->next = list1;
    }else{
        temp->next = list2;
    }
    return dummyNode->next;
}

Node* mergeKLists(vector<Node*> &listArray){
    Node* head = listArray[0];
    for(int i=1;i<listArray.size();i++){
        head = merge2LL(head, listArray[i]);
    }
    return head;
}


// Optimal
// TC - ,SC - 
