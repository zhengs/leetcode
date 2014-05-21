#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;


class Node {
public:
	int value;
	Node* left;
	Node* right;
};

stack<Node*> s;
void preorder(Node *head) {
	if(head == nullptr) {
		return;
	}
	s.push(head);
	while(s.empty() == false) {
		Node *p = s.top();
		s.pop();
		cout << p->value << endl;
		if(p->right != nullptr) {
			s.push(p->right);
		}
		if(p->left != nullptr) {
			s.push(p->left);
		}
	}
}

stack<pair<Node*, bool> > sp;

void inorder(Node *head) {
	if(head == nullptr) {
		return;
	}
	sp.push(pair<Node*, bool>(head, false));
	while(sp.empty() == false) {
		pair<Node*, bool> p = sp.top();
		sp.pop();
		if(p.first == nullptr) {
			continue;
		}
		if(p.second == false) {
			sp.push(pair<Node*, bool>(p.first->right, false));
			sp.push(pair<Node*, bool>(p.first, true));
			sp.push(pair<Node*, bool>(p.first->left, false));
		} else {
			cout << p.first->value << endl;
		}
	}	
}

void postorder(Node *head) {
	if(head == nullptr) {
		return;
	}
	sp.push(pair<Node*, bool>(head, false));
	while(sp.empty() == false) {
		pair<Node*, bool> p = sp.top();
		sp.pop();
		if(p.first == nullptr) {
			continue;
		}
		if(p.second == false) {
			sp.push(pair<Node*, bool>(p.first, true));
			sp.push(pair<Node*, bool>(p.first->right, false));
			sp.push(pair<Node*, bool>(p.first->left, false));
		} else {
			cout << p.first->value << endl;
		}
	}		
}

queue<pair<Node*, int> > q;

void levelOrder(Node* head) {
	if(head == nullptr) {
		return;
	}
	q.push(pair<Node*, int>(head, 0));
	while(q.empty() == false) {
		Node* p = q.front().first;
		int lvl = q.front().second;
		q.pop();
		if(p == nullptr)  {
			continue;
		}
		q.push(pair<Node*, int>(p->left, lvl+1));
		q.push(pair<Node*, int>(p->right, lvl+1));
		cout << p->value << endl;
	}
}

void zigzag(Node* head) {
	deque<Node*> *dNow = nullptr;
	deque<Node*> *dNext = nullptr;
	if(head == nullptr) {
		return;
	}
	bool direction = true;
	dNow = new deque<Node*>();
	dNow->push_back(head);
	while(true) {
		Node *p;
		if(direction == true) {
			p = dNow->front();
			dNow->pop_front();
		} else {
			p = dNow->back();
			dNow->pop_back();
		}
		if(p == nullptr) {
			continue;
		}
		if(dNext == nullptr) {
			dNext = new deque<Node*>();
		}
		dNext->push_back(p->left);
		dNext->push_back(p->right);
		if(dNow->empty()) {
			delete dNow;
			dNow = dNext;
			dNext = nullptr;
			direction = !direction;
		}
	}
}


class B {
	int value;
public:
	B* operator++() {
		value++;
		cout << "++B" << endl;
		return this;
	}
	B* operator++(int t) {
		B* tmp = new B(*this);
		value++;
		cout << "B++" << endl;
		return tmp;
	}

	void operator=(B& b) {
		B *tmp = new B(b);
		this->swap(tmp);
	}
	void swap(B* tmp) {
		std::swap(this->value, tmp->value);
	}
};
int main() {
	int i = 1;
	cout << (i != 1) << endl;
	B b;
	b++;
	++b;
}