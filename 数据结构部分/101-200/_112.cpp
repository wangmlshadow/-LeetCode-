#include "normal.h"

/*
����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        return solution(root, sum);
    }

    bool solution(TreeNode* root, int sum) {
        if (root->left == NULL && root->right == NULL)
            return root->val == sum;

        bool sign_1 = false, sign_2 = false;

        if (root->left != NULL)
            sign_1 = solution(root->left, sum - root->val);

        if (root->right != NULL)
            sign_2 = solution(root->right, sum - root->val);

        return sign_1 || sign_2;
    }
};