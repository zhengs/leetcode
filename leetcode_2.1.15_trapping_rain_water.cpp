#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

int water(vector<int> &heights) {
    vector<int> leftwards(heights.size(), 0);
    int total = 0;
    int maxHeight = 0;
    for(int i = 0; i < heights.size(); ++i) {
        if(i == 0) {
            leftwards[i] = 0;
            maxHeight = heights[i];
            continue;
        }
        leftwards[i] = maxHeight;
        maxHeight = max(heights[i], maxHeight);
    }
    maxHeight = 0;
    for(int i = heights.size()-1; i >= 0; --i) {
        total += max(0, min(leftwards[i], maxHeight) - heights[i]);
        maxHeight = max(heights[i], maxHeight);
    }
    return total;
}

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> vi(a, a+sizeof(a)/sizeof(a[0]));
    cout << "haha" << endl;
    cout << water(vi) << endl;
}