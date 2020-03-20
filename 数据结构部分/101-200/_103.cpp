#include "normal.h"

/*
����һ����������������ڵ�ֵ�ľ���β�α����������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // ��α������������ϼ�¼ÿһ������ķ���
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        bool sign = true;   // ���ĳ�����ʱ�Ƿ�Ϊ������
        vector<TreeNode*> cur_l;
        cur_l.push_back(root);

        while (!cur_l.empty()) {
            vector<TreeNode*> tmp_t;
            vector<int> tmp_i;

            for (int i = 0; i < cur_l.size(); i++) {
                tmp_i.push_back(cur_l[i]->val);
                
                if (cur_l[i]->left != NULL)
                    tmp_t.push_back(cur_l[i]->left);

                if (cur_l[i]->right != NULL)
                    tmp_t.push_back(cur_l[i]->right);
            }

            if (sign) {
                res.push_back(tmp_i);
                sign = false;
            }
            else {
                reverse(tmp_i.begin(), tmp_i.end());
                res.push_back(tmp_i);
                sign = true;
            }

            cur_l = tmp_t;
        }

        return res;
    }
};  // ִ����ʱ���ڴ����Ķ�����100%