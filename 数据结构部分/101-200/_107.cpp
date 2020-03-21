#include "normal.h"

/*
����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // ת�ò�α����Ľ��
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        TreeNode* end = root;
        q.push(root);

        while (!q.empty()) {
            vector<int> temp;
            TreeNode* end_2 = NULL;

            while (!q.empty()) {
                TreeNode* cur = q.front();
                temp.push_back(cur->val);
                q.pop();

                if (cur->left != NULL) {
                    q.push(cur->left);
                    end_2 = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    end_2 = cur->right;
                }
                    
                if (end == cur) {
                    end = end_2;
                    break;
                }                    
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};