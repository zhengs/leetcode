#include <iostream>
using namespace std;

class list{
public:
	int value;
	list *next;
};

list* insertion_sort(list* head) {
	if(head == NULL) {
		return NULL;
	}
	if(head->next == NULL) {
		return head;
	}
	list *p = head;
	list *q = head->next;
	head->next = NULL;
	while(q!= NULL) {
		list *tmp = p;
		while(tmp->next != NULL && tmp->next->value < q->value) {
			tmp = tmp->next;
		}
		if(tmp->next == NULL) {
			tmp->next = q;
			q = q->next;
			tmp->next->next = NULL;
		} else {
			list *tmp2 = q;
			q = q->next;
			tmp2->next = tmp->next;
			tmp->next = tmp2;
			tmp->next->next = NULL;
		}
	}
	return head->next;
}