// Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head
// Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

// Brute Force
// TC - O((2(N*M))+X log X),SC - O(N)
Node* convertArr(vector<int> &arr){
	if(arr.size()==0)return NULL;
	Node* head = new Node(arr[0]);
	Node* temp = head;
	for(int i=1;i<arr.size();i++){
		Node* newNode = new Node(arr[i]);
		temp->child = newNode;
		temp = temp->child;
	}
	return head;
}

Node* flattenLinkedList(Node* head) 
{
	Node* temp1 = head;
	vector<int> arr;
	while(temp1!=NULL){
		Node* temp2 = temp1;
		while(temp2!=NULL){
			arr.push_back(temp2->data);
			temp2 = temp2->child;
		}
		temp1 = temp1->next;
	}
	int n = arr.size();
	sort(arr.begin(),arr.end());

	Node* h1 = convertArr(arr);
	return h1;
}

// Optimal
// TC - O(2NM),SC - O(1)
Node* merge2LL(Node* list1,Node* list2){
	Node* dummyNode = new Node(-1);
	Node* temp = dummyNode;
	while(list1!=NULL && list2!=NULL){
		if(list1->data < list2->data){
			temp->child = list1;
			temp = list1;
			list1 = list1->child;
		}else{
			temp->child = list2;
			temp = list2;
			list2 = list2->child;
		}
		temp->next = NULL;
	}
	if(list1){
		temp->child = list1;
	}else{
		temp->child = list2;
	}
	return dummyNode->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next == NULL)return head;
	Node* newHead = flattenLinkedList(head->next);
	return merge2LL(head, newHead);
}
