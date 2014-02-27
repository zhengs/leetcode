#include <iostream>
using namespace std;


#define START 0
#define EXPECT_LEFT 1
#define EXPECT_RIGHT 2
#define EXPECT_E 	3
bool valid_number(string &s) {
	// remove spaces
	int i = 0;
	int state = START;
	bool couldBeSign = true;
	while(s[i] == ' ')
		i++;
	while(i<s.size()){
		switch(state){
			case START:
				if(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
					state = EXPECT_LEFT;
				} else
					return false;
				break;
			case EXPECT_LEFT:
				if(s[i] == '.') {
					state = EXPECT_RIGHT;
				} else if(s[i] == 'E' || s[i] == 'e') {
					state = EXPECT_E;
				} else if(s[i] > '9' || s[i] < '0') 
					return false;
				break;
			case EXPECT_RIGHT:
				if(s[i] == 'E' || s[i] == 'e') {
					state = EXPECT_E;
				} else if(s[i] > '9' || s[i] < '0') 
					return false;
				break;
			case EXPECT_E:
				if(s[i] > '9' || s[i] < '0') 
					return false;
				break;
			default:
				break;
		}
		i++;
	}
	return true;
}


int main() {
	string s = "1.2e1.2";
	cout << valid_number(s);
}