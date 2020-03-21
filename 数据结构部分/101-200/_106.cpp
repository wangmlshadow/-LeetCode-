#include "normal.h"

/*
����һ��������������������������������

ע��:
����Լ�������û���ظ���Ԫ�ء�
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // �������������������������
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();

        if (len == 0)
            return NULL;
        int pos = len - 1;
        return solution(inorder, 0, len - 1, postorder, pos);
    }

    TreeNode* solution(vector<int>& inorder, int start, int end, vector<int>& postorder, int& pos) {
        if (pos < 0)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pos]);
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), postorder[pos]);
        int pos_2 = iter - inorder.begin();

        if (end <= pos_2)
            root->right = NULL;
        else
            root->right = solution(inorder, pos_2 + 1, end, postorder, --pos);

        if (start >= pos_2)
            root->left = NULL;
        else
            root->left = solution(inorder, start, pos_2 - 1, postorder, --pos);

        return root;
    }
};