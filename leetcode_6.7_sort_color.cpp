#include <vector>
#include <iostream>

using namespace std;

void _sort(vector<int> &vi) {
	if(vi.size() <= 1) {
		return;
	}
	int idx_0_insert = 0;
	int idx_0_search = 0;
	int idx_2_insert = vi.size()-1;
	int idx_2_search = vi.size()-1;
	while(vi[idx_0_insert] == 0) {
		idx_0_insert++;
	}
	idx_0_search = idx_0_insert;
	while(vi[idx_2_insert] == 2) {
		idx_2_insert--;
	}
	idx_2_search = idx_2_insert;
	while(idx_0_search <= idx_2_search) {
		cout << idx_0_search << ", " << idx_0_insert << ", " << idx_2_search << ", " << idx_2_insert << endl;
		if(vi[idx_0_search] == 0) {
			swap(vi[idx_0_search], vi[idx_0_insert]);
			idx_0_search++;
			idx_0_insert++;
			while(vi[idx_0_insert] == 0) {
				idx_0_insert++;
			}
			if(idx_0_insert>idx_0_search) {
				idx_0_search = idx_0_insert;
			}
		} else if(vi[idx_0_search] == 2) {
			swap(vi[idx_0_search], vi[idx_2_insert]);
			idx_0_search++;
			idx_2_insert--;
			while(vi[idx_2_insert] == 2) {
				idx_2_insert--;
			}
			if(idx_2_search>idx_2_insert) {
				idx_2_search = idx_2_insert;
			}
		} else if(vi[idx_2_search] == 2) {
			swap(vi[idx_2_search], vi[idx_2_insert]);
			idx_2_search--;
			idx_2_insert--;
			while(vi[idx_2_insert] == 2) {
				idx_2_insert--;
			}
			if(idx_2_search>idx_2_insert) {
				idx_2_search = idx_2_insert;
			}
		} else if(vi[idx_2_search] == 0) {
			swap(vi[idx_0_insert], vi[idx_2_search]);
			idx_0_insert++;
			idx_2_search--;
			while(vi[idx_0_insert] == 0) {
				idx_0_insert++;
			}
			if(idx_0_insert>idx_0_search) {
				idx_0_search = idx_0_insert;
			}
		} else {
			idx_0_search++;
		}
	}
	cout << idx_0_search << ", " << idx_0_insert << ", " << idx_2_search << ", " << idx_2_insert << endl;
}


int main() {
	srand (time(NULL));
	vector<int> vi;
	int l = 30;
	for(int i = 0; i < l; i++) {
		vi.push_back(rand()%3);
	}
	for(int i = 0; i < l; i++) {
		cout << vi[i] << " ";
	}
	cout << endl;
	_sort(vi);
	for(int i = 0; i < l; i++) {
		cout << vi[i] << " ";
	}
}