#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

#define going_left  0
#define going_right 1

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> r;
        if(root == 0) return r;
        stack<pair<TreeNode*, int> > s;
        TreeNode* current = root;
        pair<TreeNode*, int> p;
        while(true){
            if(current != 0){
                r.push_back(current->val);
                s.push(pair<TreeNode*, int>(current, going_left));
                current = current->left;
            } else {
                while(s.empty() == false) {
                    p = s.top();
                    s.pop();
                    if(p.second == going_left) {
                        p.second = going_right;
                        s.push(p);
                        current = current->right;
                        break;
                    }
                }
                if(s.empty() == true)
                    break;
            }
        }
        
    }
};