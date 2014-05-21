
/* 2sum */
TC = O(n);
SC = O(n);
pair<int, int> twoSum(const vector<int> &vi, int sum) {
	unordered_set<int> m;
	for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
		if(m.find(sum-*it) != m.end()) {
			return pair<int, int>(sum-*it, *it);
		} else {
			m.insert(*it);
		}
	}
	return NULL;
}

/* add two numbers */
class Node {
public:
	int value;
	Node* next;
};
Node* add(Node* head1, Node* head2) {
	if(head1 == nullptr || head2 == nullptr) {
		return nullptr;
	}
	Node* p = new Node();
	Node* returnHead = p;
	int carry = 0;
	while(head1 != nullptr && head2 != nullptr) {
		p->next = new Node();
		p = p->next;
		p->value = (head1->value + head2->value + carry)%10;
		carry = (head1->value + head2->value + carry)/10;
	}
	while(head1 != nullptr) {
		p->next = new Node();
		p = p->next;
		p->value = (head1->value + carry)%10;
		carry = (head1->value + carry)/10;
	}
	while(head2 != nullptr) {
		p->next = new Node();
		p = p->next;
		p->value = (head2->value + carry)%10;
		carry = (head2->value + carry)/10;
	}
	return returnHead;
}