#include "normal.h"

/*
����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // �ݹ�ⷨ
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        vector<int> one;
        one.push_back(root->val);
        int rest = sum - root->val;

        if (rest == 0 && root->left == NULL && root->right == NULL) {
            res.push_back(one);
        }

        if (root->left != NULL)
            solution(res, one, rest, root->left);

        if (root->right != NULL)
            solution(res, one, rest, root->right);

        return res;
    }

    void solution(vector<vector<int>>& res, vector<int> one, int rest, TreeNode* root) {
        if (root->val == rest && root->left == NULL && root->right == NULL) {
            one.push_back(root->val);
            res.push_back(one);
            return;
        }

        one.push_back(root->val);
        rest -= root->val;

        if (root->left != NULL)
            solution(res, one, rest, root->left);

        if (root->right != NULL)
            solution(res, one, rest, root->right);
    }
};


// ��ջ