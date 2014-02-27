#include <vector>
#include <iostream>
#include <set>
using namespace std;

void comb(vector<int> &vi, int target, int i_start, vector<int> &current, vector<vector<int> > &r) {
	for(int i = i_start; i < vi.size(); i++) {
		if(vi[i] < target) {
			current.push_back(vi[i]);
			comb(vi, target-vi[i], i_start+1, current, r);
			current.pop_back();
		} else if(vi[i] == target) {
			current.push_back(vi[i]);
			r.push_back(current);
			current.pop_back();
		}
	}
}

void comb_main(vector<int> &vi, int target) {
	sort(vi.begin(), vi.end());
	vector<int> current;
	vector<vector<int> > r;
	comb(vi, target, 0, current, r);
	set<string> dict;
	for(int i = 0; i < r.size(); i++) {
		string s = "";
		vector<int> a = r[i];
		sort(a.begin(), a.end());
		for(int j = 0; j < a.size(); j++) {
			s = s + to_string(a[j]) + ", ";
		}
		if(dict.find(s) == dict.end()) {
			dict.insert(s);
			cout << s << endl;
		}
	}
}

int main() {
	vector<int> vi;
	vi.push_back(10);
	vi.push_back(7);
	vi.push_back(2);
	vi.push_back(1);
	vi.push_back(6);
	vi.push_back(1);
	vi.push_back(5);
	comb_main(vi, 8);
}