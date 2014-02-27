#include <iostream>
#include <string>
#include <vector>
using namespace std;


void restore(string s, int numLeft, string &sofar, vector<string> &ans) {
	if(s.size() == 0) {
		return;	
	}
	if(numLeft == 1) {
		int temp = atoi(s.c_str());
		if(temp < 0 || temp > 255) {
			return;
		} else {
			sofar += "." + s;
			ans.push_back(sofar);
			return;
		}
	}
	for(int i = 1; i < s.size(); i++) {
		string a = s.substr(0, i);
		int temp = atoi(a.c_str());
		if(temp < 0 || temp > 255) {
			continue;
		} else {

			string n;
			if(numLeft == 4) {
				n = a;
			} else {
				n = sofar + "." + a;
			}
			restore(s.substr(i), numLeft-1, n, ans);
		}
	}
}

int main() {
	string sofar = "";
	vector<string> ans;
	string s = "12223334";
	restore(s, 4, sofar, ans);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}