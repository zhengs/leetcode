#include <vector>
#include <iostream>
using namespace std;

void show(vector<int> &path) {
	for(vector<int>::iterator it = path.begin(); it != path.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

void perm(vector<int> &vi, vector<int> &path, int pos) {
	if(pos == vi.size()) {
		show(path);
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
}

int main() {
	int a[] = {1, 2, 3, 4, 5};
	vector<int> vi(&a[0], &a[4]);
	perm(vi);
}