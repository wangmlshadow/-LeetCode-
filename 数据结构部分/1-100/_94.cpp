#include "normal.h"

/*
����һ���������������������� ������
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // ���õݹ�
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> mySt;
        TreeNode* p = root;

        while (p != NULL || !mySt.empty()) {
            if (p != NULL) {
                mySt.push(p);
                p = p->left;
            }
            else {
                TreeNode* top = mySt.top();
                mySt.pop();
                result.push_back(top->val);
                p = top->right;
            }
        }

        return result;
    }
};