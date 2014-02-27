#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
	stack<int> lefts;
	int lastRight = -1;
	int max_len = 0;
	int i = 0;
	while(i < s.size()) {
		if(s[i] == '(') {
			lefts.push(i);
		} else {
			if(lefts.empty() == false) {
				lefts.pop();
				if(lefts.empty() == true)
					max_len = max(max_len, i - lastRight);
				else 
					max_len = max(max_len, i - lefts.top());
			} else {
				lastRight = i;
			}
		}
	}
	return max_len;
}