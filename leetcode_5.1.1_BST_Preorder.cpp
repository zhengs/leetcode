#include <iostream>
using namespace std;

stack<Node*> s;
void BST_Preorder(Node* root) {
	s.push(root);
	while(s.empty() == false) {
		Node* p = s.pop();
		cout << p->value;
		s.push(p->right);
		s.push(p->left);
	}
}