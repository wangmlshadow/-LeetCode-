#include "normal.h"

/*
����һ���ǿն����������������·���͡�

�����У�·��������Ϊһ������������ڵ�������ﵽ����ڵ�����С���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣
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
    int maxPathSum(TreeNode* root) {
        int max = root->val;

        transMax(root, max);

        return max;
    }

    int transMax(TreeNode* root, int& max) {   // ��¼��������ڵ�����·�������һ��
        if (root == NULL)
            return 0;

        int left = transMax(root->left, max);
        int right = transMax(root->right, max);

        int val = root->val;

        if (left > 0)
            val += left;

        if (right > 0)
            val += right;

        if (max < val)
            max = val;

        if (left > right && left > 0) 
            root->val += left;

        if (right > left && right > 0)
            root->val += right;

        return root->val;
    }
};