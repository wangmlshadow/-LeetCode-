#include "normal.h"

/*

������������������дһ�����������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
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