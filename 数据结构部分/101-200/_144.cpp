#include "normal.h"

/*
����һ������������������ ǰ�� ������
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // �ǵݹ�
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == NULL)
            return res;

        stack<TreeNode*> helper;
        TreeNode* p = NULL;
        helper.push(root);

        while (!helper.empty()) {
            p = helper.top();
            res.push_back(p->val);
            helper.pop();

            if (p->right != NULL)
                helper.push(p->right);

            if (p->left != NULL)
                helper.push(p->left);
        }

        return res;
    }
};