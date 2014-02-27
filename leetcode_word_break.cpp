#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s.size() == 0) return false;
        bool found = false;
        for(int i = 1; i <= s.size(); i++)
            if(dict.find(s.substr(0,i)) != dict.end()) {
                if(i == s.size()) 
                    return true;
                else {
                    found = wordBreak(s.substr(i), dict);
                    if(found == true)
                    	return true;
				}
			}
        return false;
    }
};

int main() {
	unordered_set<string> dict;
	dict.insert("aaaa");
	dict.insert("aaa");
	dict.insert("aa");
	Solution sl;
	cout << sl.wordBreak("aaaaaaa", dict) << endl;
}