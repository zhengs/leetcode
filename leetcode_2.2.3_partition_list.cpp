#include <iostream>
using namespace std;


class list {
public:
	int value;
	list *next;
	list(): value(0), next(NULL) {}
};

list* partition(list *head, int n) {
	if(head == NULL) return head;
	list **pSmall = NULL;
	list **pBig = NULL;
	list *p = head;
	list *newHeadSmall = NULL;
	list *newHeadBig = NULL;
	while(p != NULL) {
		if(p->value < n) {
			if(pSmall == NULL) {
				if(newHeadSmall == NULL)
					newHeadSmall = p;
				pSmall = &(p->next);
			}
			else {
				*pSmall = p;
				pSmall = &(p->next);
			}
		} else {
			if(pBig == NULL) {
				if(newHeadBig == NULL)
					newHeadBig = p;
				pBig = &(p->next);
			}
				
			else {
				*pBig = p;
				pBig = &(p->next);
			}
		}
		p = p->next;
	}
	*pSmall = newHeadBig;
	*pBig = NULL;
	return newHeadSmall;
}

int main() {}