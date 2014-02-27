#include <unordered_map>


using namespace std;


int firstMissing(vector<int> vi) {
	int min = INT_MAX;
	unordered_map<int, bool> m;
	for(int i = 0; i < vi.size(); i++) {
		int n = vi[i];
		if(m.find(n) == m.end()) {
			m[n] = true;
		}
		if(n < min) {
			min = n;
		}
	}
	i = 1;
	while(true) {
		if(m.find[min+i] == m.end())
			break;
		i++;
	}
	return min+i;
}