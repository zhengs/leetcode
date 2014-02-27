#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// CORRECT ANSWER BELOW

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL) return;
        ListNode* p = head;
        int len = 0;
        while(p->next != NULL) {
            p=p->next; 
            len++;
        }
        len++;
        if(len <= 2) return;
        int i = 0;
        p = head;
        while(i++ < (len-1)/2) p=p->next;
        ListNode* q = p->next;
        ListNode *tmp1, *tmp2;
        while(q != NULL){
            tmp1 = q->next;
            q->next = p;
            p = q;
            q = tmp1;
        }
        i = 0;
        q = head;
        while(i++ < (len-1)/2) {
            tmp1 = q->next;
            tmp2 = p->next;
            q->next = p;
            p->next = tmp1;
            q = tmp1;
            p = tmp2;
        }
        if(len > 3)
            p->next = NULL;
        else
            q->next = NULL;
    }
};

void show(ListNode* head) {
	while(head != NULL) {
		cout << head->val << " ";
		head=head->next;
	}
	cout << endl;
}
int main() {
	ListNode *p, **s; 
	p = new ListNode(-1);
	s = &p;
	for(int i = 0; i < 11; i++) {
		(*s)->next = new ListNode(i);
		s = &((*s)->next);
	}

	show(p);
	Solution sl;
	sl.reorderList(p);
	show(p);
	return 0;
}