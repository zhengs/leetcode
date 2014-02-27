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

void combinations(vector<int> &vi, vector<int> &path, int pos, int remain) {
	if(remain == 0) {
		show(path);
	}

	for(int i = pos; i < vi.size(); i++) {
		swap(vi[pos], vi[i]);
		path.push_back(vi[pos]);
		combinations(vi, path, pos+1, remain-1);
		path.pop_back();
		swap(vi[pos], vi[i]);
	}
}

void combinations(vector<int> &vi, int remain) {
	vector<int> path;
	combinations(vi, path, 0, remain);
}

int main() {
	int a[] = {1, 2, 3, 4};
	vector<int> vi(&a[0], &a[4]);
	combinations(vi, 2);

	string b = "haha";
	string c = "haha";
	if(b == c)
		cout << "111";
	else cout << "000";
}