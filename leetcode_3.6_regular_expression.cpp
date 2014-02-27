#include <iostream>
#include <string>

using namespace std;



bool isMatch(const char *s, const char *p) {
	if(p[0] == '\0') {
		return s[0] == '\0';
	}
	if(p[1] == '\0') {
		if(p[0] == '.') {
			return true;
		} else {
			return s[0] == p[0];
		}
	}
	if(p[1] == '*') {
		if(p[0] == '.') {
			return isMatch(s+1, p+2) || isMatch(s, p+2);
		} else if(s[0] == p[0]) {
			return isMatch(s+1, p);
		} else {
			return isMatch(s, p+2);
		}
	} else {
		if(p[0] == '.') {
			return isMatch(s+1, p+1);
		} else if(s[0] == p[0]) {
			return isMatch(s+1, p+1);
		} else {
			return false;
		}
	}
}

int main() {
	const char *s = "ab";
	const char *p = ".ab";
	cout << isMatch(s, p) << endl;
}