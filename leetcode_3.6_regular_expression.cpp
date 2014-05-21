#include <iostream>
#include <string>

using namespace std;


int ccount=0;
bool isMatch(const char *s, const char *p) {
	++ccount;
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
			return isMatch(s+1, p+2) || isMatch(s, p+2) || isMatch(s+1,p);
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
	const char *s = "abaaaaaaaaaaab";
	const char *p = ".*b";
	cout << isMatch(s, p) << endl;
	cout << ccount << endl;
}