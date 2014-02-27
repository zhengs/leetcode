#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> dict;
unordered_map<string, bool> path;
queue<string> q;

int dist(string &a, string &b) {
	int n;
	for(int i = 0; i<a.size(); i++) {
		n += a[i] == b[i]?0:1;
	}
	return n;
}
int ladder(string &starts, string &ends) {
	int len = 0;
	string wordNow = starts;
	while(true) {
		if(wordNow == ends)
			return len;
		path[]
		for(unordered_map<string, bool>::iterator it = dict.begin(); it != dict.end(); it++) {
			if(dist(*it, wordNow) == 1) {
				q.push_back(*it);
			}
		}
	}

}