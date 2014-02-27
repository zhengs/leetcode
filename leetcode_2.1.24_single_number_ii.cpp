#include <iostream>
#include <vector>
using namespace std;


int singleNumber(vector<int> vi) {
	int count[sizeof(int)*8] = {0};
	for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {
		int num = *it;
		// cout << "num = " << num << endl;
		for(int i = 0; i < sizeof(int)*8; i++) {
			if((num & (1<<i)) != 0) {
				// cout << i << " ";
				count[i]++;
			}
		}
		cout << endl;
	}
	int r = 0;
	for(int i = 0; i < sizeof(int)*8; i++) {
		if(count[i]%3 != 0) {
			// cout << "count[i] = " << count[i] << "; i = " << i << endl;
			r+= 1<<i;
		}
	}
	return r;
}


int main() {
	vector<int> vi;
	int a[] = {1,1,1,2,2,2,224};
	for(int i = 0; i < sizeof(a)/sizeof(*a); i++)
		vi.push_back(a[i]);
	cout << singleNumber(vi);
}