#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct RandomListNode {
	int label;
 	RandomListNode *next, *random;
 	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<RandomListNode*, RandomListNode*> m;    // from p -> q
        RandomListNode *p = head;
        RandomListNode *headr, *q;
        q = headr;
        if(p == NULL) return NULL;
        while(p != NULL) {
            q = new RandomListNode(p->label);
            m[p] = q;
            p = p->next;
            q = q->next;
        }
        p = head; q = headr;
        while(p != NULL) {
            q->random = m[p->random];
            p = p->next;
            q = q->next;
        }
        return headr;
    }
};

int main() {
	RandomListNode n(1);
	n->next = 
}