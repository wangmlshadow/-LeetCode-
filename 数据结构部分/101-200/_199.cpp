#include "normal.h"

/*
����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {   // ��α���
        vector<int> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> helper;
        helper.push(root);
        TreeNode* last = root;

        while (!helper.empty()) {
            TreeNode* cur;
            
            while (!helper.empty()) {
                if (helper.front()->left != NULL) {
                    helper.push(helper.front()->left);
                    cur = helper.front()->left;
                }

                if (helper.front()->right != NULL) {
                    helper.push(helper.front()->right);
                    cur = helper.front()->right;
                }

                if (last == helper.front()) {
                    res.push_back(helper.front()->val);
                    last = cur;
                }

                helper.pop();
            }            
        }

        return res;
    }
};