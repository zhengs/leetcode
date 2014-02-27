#include <iostream>
using namespace std;

bool valid(string &s) {
	if(s.size()==0)
		return true;
	int i = 0;
	int j = s.size()-1;
	while(i<= j) {
		if(s[i] != s[j]) 
			return false;
		i++;
		j--;
	}
	return true;
}