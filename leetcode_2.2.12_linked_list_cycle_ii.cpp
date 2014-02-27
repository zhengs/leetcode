#include <iostream>
using namespace std;

class Node{
public:
	int value;
	Node *next;
	Node(): value(0), next((Node*)NULL) {}
};

Node* findCircle(Node *head) {
	// determine if a circle exists first
	Node* fast;
	Node* slow;

	if(head == NULL) return NULL;
	if(head->next == NULL) return NULL;
	if(head->next->next == NULL) return NULL;
	slow = head->next;
	fast = head->next->next;
	bool found = false;
	while(true) {
		if(slow == fast) {
			found = true;
			break;
		}
		if(slow == NULL || fast == NULL)
			return NULL;
		slow = slow->next;
		fast = fast->next;
		if(fast == NULL) return NULL;
		if(slow == fast) {
			found = true;
			break;
		}
		fast = fast->next;
	}

	// find the joint
	Node* mark = fast;
	fast = fast->next;
	slow = head;
	int ifast = 0;
	int islow = 0;
	while(slow != mark) {
		islow++;
	}
	while(fast != mark) {
		ifast++;
	}
	slow = head;
	fast = mark->next;
	if(ifast > islow) {
		fast = fast->next;
		ifast--;
	} else if(ifast < islow){
		slow = slow->next;
		islow--;
	}
	while(fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}