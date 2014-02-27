#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node():value(0),next((Node*)NULL) {}

};

void reorder(Node* head) {
	if(head == NULL) return;
	if(head->next == NULL) return;
	if(head->next->next == NULL) return;
	Node* fast = head->next->next;
	Node* slow = head->next;
	while(fast != NULL){
		slow = slow->next;
		fast = fast->next;
		if(fast == NULL) break;
		fast = fast->next;
	}

	// not finished
}