#include "normal.h"

/*

����һ��������������ÿ����㶼���һ�� 0-9 �����֣�ÿ���Ӹ���Ҷ�ӽڵ��·��������һ�����֡�

���磬�Ӹ���Ҷ�ӽڵ�·�� 1->2->3 �������� 123��

����Ӹ���Ҷ�ӽڵ����ɵ���������֮�͡�

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
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
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return root->val;

        int sum = 0;

        if (root->left != NULL)
            solution(root->left, root->val, sum);

        if (root->right != NULL)
            solution(root->right, root->val, sum);

        return sum;
    }

    void solution(TreeNode* root, int ahead, int& sum) {
        if (root->left == NULL && root->right == NULL) {
            sum += (10 * ahead + root->val);
            return;
        }

        if (root->left != NULL)
            solution(root->left, ahead * 10 + root->val, sum);

        if (root->right != NULL)
            solution(root->right, ahead * 10 + root->val, sum);
    }
};