#include "normal.h"

/*
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

�����У�һ�ø߶�ƽ�����������Ϊ��

һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int left = 0, right = 0;

        return solution(root, left, right) && abs(left - right) <= 1;
    }

    bool solution(TreeNode* root, int& left, int& right) {  // �ж����������Ƿ�Ϊƽ������������������������ĸ�
        if (root == NULL) {
            left = 0;
            right = 0;
            return true;
        }

        int left_1 = 0, left_2 = 0;
        int right_1 = 0, right_2 = 0;

        bool sign_l = solution(root->left, left_1, right_1);
        bool sign_r = solution(root->right, left_2, right_2);

        left = 1 + max(left_1, right_1);
        right = 1 + max(left_2, right_2);

        return sign_l && sign_r && abs(left - right) <= 1;
    }
};