#include <iostream>
#include <string>
using namespace std;


int findStart(string s) {
	int i = 0; 
	int k = s.size()-1;
	int j = (i+k)/2;
	while(true){
		if(i == j || j == k)
			return j+1;
		if(s[i] - '0' <= s[j] - '0') {
			i = j;
		} else {
			k = j;
		}
		j = (i+k)/2;
	}
}


int main() {
	cout << findStart("466611112");
}