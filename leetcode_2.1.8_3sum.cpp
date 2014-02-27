#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > _3sum(vector<int> S, int target) {
	if(S.size() < 3) return (vector<vector<int> >) NULL;
	sort(S.begin(), S.end());
	vector<vector<int> > r;
	for(int i = 0; i < S.size()-2; i++) {
		int left = i+1; 
		int right = S.size()-1;
		int sum1 = target - S[i];
		while(left < right) {
			if(S[left] + S[right] == sum1) {
				vector<int> *vi = new vector<int>(3, 0);
				vi[0] = S[i]; vi[1] = S[left]; vi[2] = S[right];
				r.push_back(vi);
			} else if(S[left] + S[right < sum1]) {
				left++;
			} else {
				right++;
			}
		}
	}
	return r;
}

int main() {
	vector<vector<int> > vvi;
	vvi.push_back(vector<int>(3, 0));
	vvi.push_back(vector<int>(4,0));
	vector<int> *vi = new vector<int>(1,1);
	vvi.push_back(*vi);
	vi = new vector<int>(3,3);
	vvi.push_back(*vi);

	for(vector<vector<int> >::iterator it = vvi.begin(); it != vvi.end(); it++) {
		vector<int> vi = *it;
		for(vector<int>::iterator it2 = vi.begin(); it2 != vi.end(); it2++) {
			cout << (*it2) << " ";
		}
		cout << endl;
	}
}