#include <iostream>

using namespace std;

// iterative
int minDepth(node* root) {
	stack<pair<node*, int> > sn;
	if(root == NULL) return 0;
	sn.push(pair<node*, int>(root, 0));
	int min_d = INT_MAX;
	while(sn.empty() != true) {
		pair<node*, int> _pair = sn.pop();
		node* p = _pair.first;
		if(p->left == NULL && p->right == NULL && min_d > _pair.second) {
			min_d = _pair.second;
		}
		if(p->right != NULL) {
			sn.push(pair<node*, int>(p.right, _pair.second+1));	
		}
		if(p->left != NULL) {
			sn.push(pair<node*, int>(p.left, _pair.second+1));
		}
	}
}