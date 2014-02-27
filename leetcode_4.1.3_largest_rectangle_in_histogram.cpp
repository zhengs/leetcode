#include <stack>
#include <iostream>
#include <vector>
using namespace std;


int area(vector<int> &vi) {
	stack<pair<int, int> > si;
	int maxArea = 0;
	for(int i = 0; i < vi.size(); i++) {
		if(si.size() == 0 || vi[i] >= si.top().first)
			si.push(pair<int, int>(vi[i], i));
		else {
			while(si.size() != 0 && si.top().first > vi[i]) {
				int now = si.top().first;
				int width = i - si.top().second;
				si.pop();
				if(maxArea < now * width)
					maxArea = now * width;
			}
		}
	}
	return maxArea;
}

int main() {
	vector<int> vi;
	vi.push_back(100);
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(6);
	vi.push_back(2);
	vi.push_back(3);
	cout << area(vi);
}