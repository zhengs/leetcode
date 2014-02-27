#include <iostream>
using namespace std;


class list{
public:
	int value;
	list* next;
	list(): value(0), next((list*)NULL) {}
};

class node{
public:
	int value;
	node* left;
	node* right;
	node(int v): value(v), left((node*)0), right((node*)0) {}
};

node* convert(list *head) {
	if(head == NULL) {
		return NULL;
	}
	return convertHelper(head, 0, length(head));
}

int length(list*head) {
	int len = 0;
	while(head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

int getValue(list *head, int pos) {
	while(head != NULL && pos-- >0) {
		head = head->next;
	}
	if(head != NULL) {
		return head->value;
	} else {
		return -1;
	}
}
node* convertHelper(list* head, int start, int end) {
	if(start > end) {
		return NULL;
	}
	int len = end - start + 1;	// return the length of this list
	node* p = new node(getValue(head, len/2));		// get a value of a list node
	p->left = convertHelper(head, start, len/2-1);
	p->right = convertHelper(head, len/2+1, end);


}
