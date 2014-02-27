#include <vector>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

void generate(int left, string &sofar, vector<string> &r, stack<char> &s) {
	if(left == 0) {
		if(s.empty() == true) {
			r.push_back(sofar);
			return;
		} else {
			return;
		}
	}
	for(int i = 0; i < 2; i++) {
		if(i == 0) {
			if(s.empty() == true) {
				s.push('(');
				sofar += "(";
				generate(left-1, sofar, r, s);
				sofar = sofar.substr(0, sofar.size()-1);
				s.pop();
			} else {
				s.push('(');
				sofar += "(";
				generate(left-1, sofar, r, s);
				sofar = sofar.substr(0, sofar.size()-1);
				s.pop();
			}
		} else {
			if(s.empty() == true) {
				continue;
			} else if(s.top() == '(') {
				char c = s.top();
				s.pop();
				sofar += ")";
				generate(left-1, sofar, r, s);
				sofar = sofar.substr(0, sofar.size()-1);
				s.push(c);
			} else {
				s.push(')');
				sofar += ")";
				generate(left-1, sofar, r, s);
				sofar = sofar.substr(0, sofar.size()-1);
				s.pop();
			}
		}
	}
}

void generate_main(int n) {
	stack<char> sc;
	vector<string> vs;
	string sofar = "";
	generate(n*2, sofar, vs, sc);
	for(std::vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
		cout << (*it) << endl;
	}
}
int main() {
	generate_main(3);
}