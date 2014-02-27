#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void show(vector<int> &path) {
	for(vector<int>::iterator it = path.begin(); it != path.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

unordered_map<string, vector<int> > m;

void save(vector<int> &path) {
	string s = "";
	for(int i = 0; i < path.size(); i++){
		s += to_string(path[i]) + ", ";
	}
	if(m.find(s) == m.end()) {
		m[s] = path;
	}
}
void perm(vector<int> &vi, vector<int> &path, int pos) {
	if(pos == vi.size()) {
		save(path);
		return;
	}

	for(int i = pos; i < vi.size(); i++) {
		swap(vi[pos], vi[i]);
		path.push_back(vi[pos]);
		perm(vi, path, pos+1);
		path.pop_back();
		swap(vi[pos], vi[i]);
	}
}
void perm(vector<int> &vi) {
	vector<int> path;
	perm(vi, path, 0);
	for(unordered_map<string, vector<int> >::iterator it = m.begin(); it != m.end(); it++) {
		show((*it).second);
	}
}

int main() {
	int a[] = {1, 1, 3};
	vector<int> vi(&a[0], &a[3]);
	perm(vi);
}