#include "normal.h"

/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // ʹ�ö�����Ϊ�������в�α���
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* end = root;   // ��¼ÿһ������һ���ڵ㣬����ȷ���Ƿ������һ��

        while (!q.empty()) {
            vector<int> temp;
            TreeNode* last;
            TreeNode* cur;
            while (!q.empty()) {
                cur = q.front();
                temp.push_back(cur->val);
                
                if (cur->left != NULL) {
                    q.push(cur->left);
                    last = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    last = cur->right;
                }

                q.pop();

                if (cur == end) {
                    end = last;
                    break;
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};