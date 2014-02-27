#include <string>
#include <iostream>
using namespace std;


int factor(int i) {
	if(i == 0) return 1;
	return i * factor(i-1);
}

string permSeq(string s, int k) {
	int f = factor(s.size()-1);
	int i = k / f;
	cout << "i = " << i << endl;
	string sub = s.substr(0, i) + s.substr(i+1);
	cout << "sub = " << sub << endl; 
	cout << "k = " << k << " " << f << endl;
	string perm;
	if(sub.size() != 0)
		perm = s[i] + permSeq(sub, k%f);
	else
		perm = "";
	return perm;
}


int main() {
	cout << permSeq("123", 3);

	return 1;
}