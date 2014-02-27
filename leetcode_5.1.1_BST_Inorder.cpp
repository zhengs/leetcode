#include <iostream>
using namespace std;

stack<Pair<Node*, bool> > s;	// the second element indicates if this node is vistied the first time
void BST_Inorder(Node* root) {
	s.push(Pair<Node*, bool>(root, true));
	while(s.empty() == false) {
		Pair<Node*, bool> p = s.top();
		s.pop();
		if(p.second == true) {
			if(p.first->right != NULL) s.push(Pair<Node*, bool>(p.first->right, true));
			s.push(Pair<Node*, bool>(p.first, false));
			if(p.first->left != NULL) s.push(Pair<Node*, bool>(p.first->left, true));
		} else {
			cout << p.first->value << endl;
		}
	}
}