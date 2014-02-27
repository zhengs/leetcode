#include <string>
#include <iostream>
using namespace std;


int length_of_last_word(string s) {
	int i = s.size()-1;
	int len = 0;
	while(s[i] == ' ' && i >= 0)
		i--;
	if(i < 0)
		return len;
	int j = i;
	while(s[j] != ' ' && j >= 0)
		j--;
	return i - j;

}

int main() {
	string s = "   1   111";
	cout << length_of_last_word(s) << endl;
}