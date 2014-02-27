#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > _3sum(vector<int> &vi, int target) {
	sort(vi.begin(), vi.end());
	vector<vector<int> > results;
	for(int i = 0; i < vi.size(); i++) {
		int j = i+1;
		int k = vi.size()-1;
		while(j < vi.size() && j < k) {
			// cout << i << " " << j << " " << k << endl;
			if(vi[j] + vi[k] == target - vi[i]) {
				vector<int> r(3);
				r[0] = vi[i]; r[1] = vi[j]; r[2] = vi[k];
				results.push_back(r);
				break;
			} else if(vi[j] + vi[k] < target - vi[i]) {
				j++;
				if(i==j)j++;
			} else {
				k--;
				if(k == i) k--;
			}
		}
	}
	return results;
}

int main() {
	std::vector<int> vi;
	for(int i = 0; i < 10; i++)
		vi.push_back(i);
	vector<vector<int> > vvi = _3sum(vi, 15);
	for(vector<vector<int> >::iterator it = vvi.begin(); it != vvi.end(); it++) {
		for(vector<int>::iterator iit = (*it).begin(); iit != (*it).end(); iit++) {
			cout << (*iit) << " ";
		}
		cout << endl;
	}
}