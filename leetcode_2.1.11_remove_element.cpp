#include <iostream>
#include <vector>
using namespace std;

int remove(vector<int> *a, int toRemove) {
	int pa = 0;
	int pWrite = 0;
	while(pa < a->size()) {
		if((*a)[pa] != toRemove) {
			(*a)[pWrite] = (*a)[pa];
			pa++;
			pWrite++;
		} else {
			pa++;
		}
	}
	return pWrite;
}


int main() {
	vector<int> a;
	for(int i = 0; i < 10; i++) {
		a.push_back(i);
	}
	int len = remove(&a, 3);
	for(int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
}