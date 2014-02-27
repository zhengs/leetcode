#include <iostream>
#include <queue>
using namespace std;

queue<Pair<Node*, bool> > q;	// the second element indicates if this node is vistied the first time
vector<vector<int> > BST_Levelorder(Node* root) {
	q.push_back(root);
	int currentLevel = 1;
	int nextLevel = 0;
	int level = 0;
	vector<vector<int> > vvi;
	vector<int> *pvi = NULL;
	while(q.empty() == false) {
		Node* n = q.pop_front();
		currentLevel--;
		if(pvi == NULL) {
			pvi = new vector<int>();
		}
		pvi.push_back(n->value);
		if(n->left) {
			q.push_back(n->left);
			nextLevel++;
		}
		if(n->right) {
			q.push_back(n->right);
			nextLevel++;
		}
		if(currentLevel == 0) {
			currentLevel = nextLevel;
			nextLevel = 0;
			vvi.push_back(*pvi);
			pvi = new vector<int>();
		}
	}
	return vvi;
}