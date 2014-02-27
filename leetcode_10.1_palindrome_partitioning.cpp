#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


bool parlindrome(string &s) {
	if(s.size() == 0)
		return true;
	int i = 0; 
	int j = s.size()-1;
	while(i<j) {
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

vector<vector<string> > _partition(string s) {
	if(s.size() == 0)
		return vector<vector<string>();
	vector<vector<string> > vvs;
	if(parlindrome(s) == true) {
		vvs.push_back(vector<string>(s));
	}
	for(int i = 1; i < s.size(); i++) {
		
		vector<vector<string> > vvs1 = _partition(s.substr(0, i));
		
		vector<vector<string> > vvs2 = _partition(s.substr(i, s.size()-i));
		
		for(int i = 0; i < vs1.size(); i++)
			vs.push_back(vs1[i]);
		for(int i = 0; i < vs2.size(); i++)
			vs.push_back(vs2[i]);
	}
	return vs;
}

int main() {
	string s = "abcdefg";
	vector<string> vs = _partition(s);
	for(int i = 0; i < )
}