#include <iostream>
using namespace std;

// time complexity: O(n), space complexity: O(logn)
int maxPath(node* root) {
	if(root == NULL) {
		return 0;
	}
	int l = maxPath(root->left);
	int r = maxPath(root->right);
	if(max(l,r) > 0) {
		return max(l,r) + root->value;
	} else {
		return root->value;
	}

}