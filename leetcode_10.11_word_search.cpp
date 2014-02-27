#include <vector>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

bool match(int i, int j, vector<vector<char> > &vvc, string &s, int pos, set<string> &dict) {
	if(pos == 0) {
		return true;
	}
	bool a, b, c, d;
	if(i-1 >= 0 && vvc[i-1][j] == s[pos] && dict.find(to_string(i) + ", " + to_string(j)) == dict.end()) {
		dict.insert(to_string(i) + ", " + to_string(j));
		a = match(i-1,j,vvc, s, pos+1, dict);
		dict.erase(to_string(i) + ", " + to_string(j));
	}
	if(j-1 >= 0 && vvc[i][j-1] == s[pos] && dict.find(to_string(i) + ", " + to_string(j)) == dict.end()) {
		dict.insert(to_string(i) + ", " + to_string(j));
		a = match(i,j-1,vvc, s, pos+1, dict);
		dict.erase(to_string(i) + ", " + to_string(j));
	}
	if(i+1 < && vvc[i-1][j] == s[pos] && dict.find(to_string(i) + ", " + to_string(j)) == dict.end()) {
		dict.insert(to_string(i) + ", " + to_string(j));
		a = match(i-1,j,vvc, s, pos+1, dict);
		dict.erase(to_string(i) + ", " + to_string(j));
	}
}


bool search(vector<vector<char> > &vvc, string &s) {
	for(int i = 0; i < vvc.size(); i++) {
		for(int j = 0; j < vvc[0].size(); j++) {
			if(vvc[i][j] == s[0]) {
				if(match(i, j, vvc, s.substr(1))) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {

}