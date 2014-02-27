#include <iostream>
using namespace std;

class list{
public:
	int value;
	list *next;
};

list* merge(list *first, list *second) {
	if(first == NULL && second == NULL) {
		return NULL;
	}
	if(first == NULL) {
		return second;
	}
	if(second == NULL) {
		return first;
	}
	list *dummy = new list(0);
	list *p = dummy;
	while(first != NULL && second != NULL) {
		if(first->value < second->value) {
			dummy->next = first;
			first = first->next;
		} else {
			dummy->next = second;
			second = second->next;
		}
		dummy = dummy->next;
	}
	if(first != NULL) {
		dummy->next = first;
	} else {
		dummy->next = second;
	}
	return p->next;
}