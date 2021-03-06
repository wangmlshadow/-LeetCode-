#include "normal.h"

/*

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solution(p, q);
    }

    bool solution(TreeNode* p, TreeNode* q) {
        if (p == NULL)
            return q == NULL;

        if (q == NULL)
            return p == NULL;

        if (p->val != q->val)
            return false;

        return solution(p->left, q->left) && solution(p->right, q->right);
    }
};