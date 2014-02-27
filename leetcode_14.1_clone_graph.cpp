#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* cloneDFS(UndirectedGraphNode* node, 
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m) {
	if(m.find(node) != m.end()) {
		return m[node];
	}
	UndirectedGraphNode* p = new UndirectedGraphNode(node->label);
	for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin();
		it != node->neighbors.end(); it++) {
		p->neighbors.push_back(cloneDFS(*it, m));	
	}
	m[node] = p;
	return p;
}

UndirectedGraphNode* cloneBFS(UndirectedGraphNode* head) {
	queue<UndirectedGraphNode*> q;
	unordered_map<UndirectedGraphNode*, pair<UndirectedGraphNode*, bool> > m;
	q.push(head);
	while(q.empty()==false) {
		UndirectedGraphNode* node = q.front();
		q.pop();
		if(m.find(node) == m.end()) {
			UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
			m[node] = pair<UndirectedGraphNode*, bool>(newNode, false);
		}
		for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin();
			it != node->neighbors.end(); it++) {
			q.push(*it);
		}
	}
	q.push(head);
	while(q.empty()==false) {
		UndirectedGraphNode* node = q.front();
		q.pop();
		if(m[node].second == false) {
			UndirectedGraphNode* p = m[node].first;
			for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin();
				it != node->neighbors.end(); it++) {
				p->neighbors.push_back(m[*it].first);
			}
			m[node].second = true;
		}
	}
	return m[head].first;
}
UndirectedGraphNode* cloneDFS_main(UndirectedGraphNode *head) {
	if(head == NULL) {
		return NULL;
	}
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
	cloneDFS(head, m);
}