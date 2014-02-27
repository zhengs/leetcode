#include <vector>
using namespace std;

class List{
public:
	int value;
	List *next;
	List():value(0), next((List*)NULL) {}
};

void removeDups(List* head) {
	// the list is sorted already
	List* p = head;
	List** pnext = &(head->next);
	int curValue = head->value;
	while(*pnext != NULL) {
		if((*pnext)->value == curValue) {
			List *toDelete = *pnext;
			*pnext = (*pnext)->next;
			delete toDelete;
		} else {
			curValue = (*pnext)->value;
			pnext = &((*pnext)->next);
		}
	}
}

