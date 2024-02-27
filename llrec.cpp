#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
// #include <iostream>
// using namespace std; 

void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(!head){ //base case
		smaller=nullptr;
		larger=nullptr;
		return;
	}

	if(head->val <= pivot){
		smaller=head;
		llpivotHelper(head->next, smaller->next, larger, pivot);
	}
	else{
		larger=head;
		llpivotHelper(head->next, smaller, larger->next, pivot);
	}
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	llpivotHelper(head,smaller,larger,pivot);
	head=nullptr;
	return;
}

// void printLL(Node* head){ //test code
// 	while(head){
// 		cout << head->val << " ";
// 		head=head->next;
// 	}
// 	cout << endl;
// }

// int main(){ 
// 	Node* p4 = new Node(3, nullptr);
// 	Node* p3 = new Node(8,p4);
// 	Node* p2 = new Node(4,p3);
// 	Node* head=new Node(2,p2);
// 	printLL(head);

// 	Node* smaller;
// 	Node* larger;
// 	llpivot(head, smaller, larger, 5);
// 	printLL(smaller);
// 	printLL(larger);
// 	printLL(head);

// 	return 0;
// }


