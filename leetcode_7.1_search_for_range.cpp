#include <vector>
#include <iostream>

using namespace std;

pair<int, int>* search(vector<int> vi, int k) {
	if(vi.size() == 0) {
		return (pair<int, int>*) NULL;
	}
	int search_start = 0, search_end = vi.size()-1;
	int start, end;
	int i = (search_start+search_end)/2;
	while(search_start <= search_end) {
		cout << search_start << "; " << search_end << endl;
		if(vi[i] < k) {
			search_start = i+1;
			i = search_start + (search_end - search_start)/2;
		} else if(vi[i] > k) {
			search_end = i-1;
			i = search_start + (search_end - search_start)/2;
		} else {
			if(i == 0 || vi[i-1] != k) { // found left
				start = i;
				break;
			} else {
				search_end = i-1;
				i = search_start + (search_end - search_start)/2;
			}
		}
	}
	cout << "haha: " << start << ", " << end << ", " << search_start << ", " << search_end << endl;
	if(search_start > search_end) {
		return (pair<int, int>*) NULL;
	}
	search_start = start;
	search_end = vi.size()-1;
	i = search_start + (search_end - search_start)/2;
	cout << search_start << "; " << search_end << endl;
	while(search_start <= search_end) {
		cout << search_start << "; " << search_end << "; " << i << endl;
		if(vi[i] < k) {
			search_start = i+1;
			i = search_start + (search_end - search_start)/2;
		} else if(vi[i] > k) {
			search_end = i-1;
			i = search_start + (search_end - search_start)/2;
		} else {
			if(i == vi.size()-1 || vi[i+1] != k) { // found left
				end = i;
				break;
			} else {
				search_start = i+1;
				i = search_start + (search_end - search_start)/2;
			}
		}
	}
	return new pair<int,int>(start, end);
}

int main() {
	srand (time(NULL));
	vector<int> vi;
	int l = 30;
	for(int i = 0; i < l; i++) {
		vi.push_back(rand()%10);
	}
	sort(vi.begin(), vi.end());
	cout << vi[13] << endl;
	for(int i = 0; i < l; i++) {
		cout << vi[i] << " ";
	}
	cout << endl;
	pair<int, int>* p = search(vi, vi[1]);
	cout << vi[13] << ": " << p->first << ", " << p->second << endl;
}
