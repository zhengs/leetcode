
#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <unordered_set>
#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<char, int> records;
        int currentHeadPos = 0;
        int max = 0;
        int currentLen = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(records.find(c) == records.end()) {
                records[c] = i;
            } else {
                if(records[c] >= currentHeadPos) {
                    currentHeadPos = records[c] + 1;
                    records[c] = i;
                } else {
                	records[c] = i;
                }
            }
            currentLen = i - currentHeadPos + 1;					
            if(currentLen > max)
                max = currentLen;
            cout << "id: " << i << " char: " << c << " PosInHash: " << records[c] << " currentHeadPos: " << currentHeadPos << " currentLen: " << currentLen << " max: " << max << endl;
        }
        return max;
    }
};

int main() {


	Solution sl;
	cout << sl.lengthOfLongestSubstring("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");

	return 0;
}