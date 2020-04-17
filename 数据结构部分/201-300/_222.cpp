#include "normal.h"

/*
����һ����ȫ����������������Ľڵ������
˵����
��ȫ�������Ķ������£�����ȫ�������У�������ײ�ڵ����û�����⣬����ÿ��ڵ���
���ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ�á�����ײ�Ϊ�� h �㣬��
�ò���� 1~ 2h ���ڵ㡣
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {  // ��α���
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        TreeNode* end = root;

        while (!q.empty()) {
            TreeNode* cur;

            while (!q.empty()) {
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                    cur = q.front()->left;
                }

                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                    cur = q.front()->right;
                }

                cnt++;

                if (q.front() == end) {
                    end = cur;
                    q.pop();
                    break;
                }

                q.pop();
            }
        }

        return cnt;
    }
};