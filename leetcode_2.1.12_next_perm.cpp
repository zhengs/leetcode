#include <iostream>
#include <string>
#include <vector>
using namespace std;

void next(vector<int>* vi) {
	bool found = false;
	for(int i = (*vi).size()-2; i >= 0; i--) {
		vector<pair<int, int> > bigger;
		for(int j = i+1; j < (*vi).size(); j++) {
			if((*vi)[j] > (*vi)[i])
				bigger.push_back(pair<int, int>((*vi)[j], j));
		}
		if(bigger.size() != 0) {
			found = true;
			int smallest = 100000;
			int smallest_idx;
			for(vector<pair<int, int> >::iterator it = bigger.begin(); it != bigger.end(); it++)
				if((*it).first < smallest) {
					smallest = (*it).first;
					smallest_idx = (*it).second;
				}
			int temp = (*vi)[i];
			(*vi)[i] = smallest;
			(*vi)[smallest_idx] = temp;
			vector<int> vi2;
			for(int k = i+1; k < (*vi).size(); k++) 
				vi2.push_back((*vi)[k]);
			sort(vi2.begin(), vi2.end());
			for(int k = i+1; k < (*vi).size(); k++) 
				(*vi)[k] = vi2[k-i-1];
			break;
		}
	}
	if(found == false)
		sort((*vi).begin(), (*vi).end());
	return;
}

int main() {
	vector<int> vi;
	vi.push_back(5);
	vi.push_back(4);
	vi.push_back(3);
	vi.push_back(2);
	vi.push_back(1);
	for(int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;
	next(&vi);
	for(int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;
}
