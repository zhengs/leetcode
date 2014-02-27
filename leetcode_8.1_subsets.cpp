#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > vvi;

void subsets(vector<int> &vi, vector<int> &sofar, int step) {
	if(step == vi.size()) {
		vvi.push_back(sofar);
		return;
	}
	if(step == 0 || vi[step-1] != vi[step] || 
		(vi[step-1] == vi[step] && sofar[sofar.size()-1] == vi[step]))
		sofar.push_back(vi[step]);
	subsets(vi, sofar, step+1);
	sofar.pop_back();
	subsets(vi, sofar, step+1);
	return;
}

void subsets(vector<int> &vi) {
	vector<int> sofar;
	subsets(vi, sofar, 0);
}


int main() {
	int haha[] = {0, 2, 2};
	vector<int> vi(&haha[0], &haha[sizeof(haha)/sizeof(haha[0])]);
	for(int i = 0; i < vi.size(); i++)
		cout << vi[i] << ", ";
	cout << endl << endl;
	subsets(vi);
	cout << "[" << endl;
	for(int i = 0; i < vvi.size(); i++) {
		cout << "[";
		for(int j = 0; j < vvi[i].size();j++)
			cout << vvi[i][j] << " ";
		cout << "], " << endl;
	}
	cout << "]" << endl;
}