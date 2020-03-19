#include "normal.h"

/*

����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {       
        return solution(root, NULL, NULL);
    }

    bool solution(TreeNode* root, TreeNode* min, TreeNode* max) {     // �������½�
        if (root == NULL)
            return true;

        if (min != NULL && root->val <= min->val)
            return false;

        if (max != NULL && root->val >= max->val)
            return false;

        return solution(root->left, min, root) && solution(root->right, root, max);
    }
};