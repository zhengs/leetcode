#include <iostream>
using namespace std;


void connect(node* root) {
	connect(root, NULL);
}

void connect(node* n1, node* n2) {
	n1->next = n2;
	connect(n1->left, n1->right);
	if(n2 != NULL) {
		connect(n1->right, n2->left);
	}
	else {
		connect(n1->right, NULL);
	}
}