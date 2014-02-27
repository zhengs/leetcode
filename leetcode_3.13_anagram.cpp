#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, vector<string> > anagram(vector<string> vs) {
	unordered_map<string, std::vector<string> >m;
	for(vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
		string s = *it;
		sort(s.begin(), s.end());
		if(m.find(s) == m.end()) {
			vector<string> *vs = new vector<string>();
			m[s] = *vs;
			m[s].push_back(*it);
		} else {
			m[s].push_back(*it);
		}
	}
	return m;
}