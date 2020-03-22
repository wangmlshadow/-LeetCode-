#include "normal.h"

/*
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {  // ���ò�α����ķ�ʽ
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int cnt = 1;
        queue<TreeNode*> q;
        TreeNode* end = root;
        q.push(root);

        while (!q.empty()) {
            TreeNode* end_2 = NULL;

            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left == NULL && cur->right == NULL)
                    return cnt;

                if (cur->left != NULL) {
                    q.push(cur->left);
                    end_2 = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    end_2 = cur->right;
                }

                if (cur == end) {
                    end = end_2;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

// �������õݹ�����