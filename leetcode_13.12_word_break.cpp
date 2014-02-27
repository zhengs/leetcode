#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool break(string &s, set<string> dict) {
	vector<bool> f(s.size(), true);
	for(i = 1; i < s.size(); i++) {
		bool r = false;
		for(int j = 1; j < i; j++) {
			r = r || (f[i-j] && s[])
		}
	}
}

int main() {
	string s = "ekfakeflkejfkahkfhkafjkejkfjkakdjf";
	cout << kth(s, 11) << endl;
	sort(s.begin(), s.end());
	cout << s << endl;
}