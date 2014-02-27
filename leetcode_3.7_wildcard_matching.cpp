#include <iostream>
#include <string>

using namespace std;



bool isMatch(const char *s, const char *p) {
	if(s[0] == '\0') {
		if(p[0] == '*' && p[1] == '\0') {
			return true;
		} else if(p[0] == '\0') {
			return true;
		} else {
			return false;
		}
	}
	if(p[0] == '?') {
		return isMatch(s+1, p+1);
	}
	if(p[0] == '*') {
		return isMatch(s+1, p) || isMatch(s+1, p+1) || isMatch(s, p+1);
	}
	return (s[0] == p[0]) && isMatch(s+1, p+1);
}

int main() {
	const char *s = "3";
	const char *p = "*3";
	cout << isMatch(s, p) << endl;
}