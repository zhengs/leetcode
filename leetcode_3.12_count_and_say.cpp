#include <iostream>
using namespace std;

string num2str(int num) {
	// cout << "num = " << num << endl;
	string s = "";
	char c;
	if(num/10 == 0) {
		c = '0' + num%10;
		return s + c;
	}
	c = '0' + num%10;
	return num2str(num/10) + c;
}

string count_and_say(int n) {
	if(n == 0)
		return "";
	if(n == 1)
		return "1";
	if(n == 2)
		return "11";
	string s = "11";
	for(int i = 2; i < n; i++){
		string p = "";
		int j = 1;
		int d = s[0];
		int count = 1;
		while(j < s.size()) {
			if(s[j] == d) {
				count++;
				j++;
			} else {
				p += num2str(count) + num2str(d - '0');
				d = s[j];
				count = 1;
				j++;
			}
		}
		p += num2str(count) + num2str(d - '0');
		// cout << "p = " << p << endl;
		s = p;
	}
	return s;
}

int main() {
	for(int i = 0; i < 10; i++)	
		cout << count_and_say(i) << endl;
}