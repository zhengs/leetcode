#include <iostream>
#include <vector>
using namespace std;

void removeElement(string &vi, char target) {
	int i2Read = 0;
	int i2Write = 0;
	while(i2Read < vi.size()) {
		if(vi[i2Read] != target) {
			vi[i2Write] = vi[i2Read];
			i2Read++;
			i2Write++;
		} else
			i2Read++;
	}	
	vi[i2Write] = 0;
}


int main() {
	string s = "kdaiefjiafjfkajfkrhgkajfkajdkfajeifajefl;akfdafkad";
	printf("%d\n", s[s.size()]);
	removeElement(s, 'k');
	removeElement(s, 'd');
	removeElement(s, 'a');
	cout << s;
}