#include "normal.h"

/*
����һ�����������ҳ��������ȡ�

�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // �����ò�α����ķ�������Ҳ�����õݹ����������õ�ʱ�ݹ�ķ���
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = 0, right = 0;

        if (root->left != NULL)
            left = maxDepth(root->left);

        if (root->right != NULL)
            right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};   // �ݹ鲻��Ҫ����Ĵ洢�ռ䣬���ǱȽ���