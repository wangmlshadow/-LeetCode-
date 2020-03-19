#include "normal.h"

/*
�����������е������ڵ㱻����ؽ�����

���ڲ��ı���ṹ������£��ָ��������
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        vector<TreeNode*> vec;
        TreeNode* p = root;

        while (p != NULL || !st.empty()) {    // ��ȡ�����������
            if (p != NULL) {
                st.push(p);
                p = p->left;
            }
            else {
                vec.push_back(st.top());
                p = st.top()->right;
                st.pop();
            }               
        }

        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i]->val > vec[i + 1]->val) {    // Ѱ����Ҫ�����������㣬��������Ӧ�����򣬴�����ʼ����ʼѰ��
                int j = i + 1;

                while (j + 1 < vec.size() && vec[i]->val > vec[j + 1]->val)
                    j++;

                int val = vec[i]->val;
                vec[i]->val = vec[j]->val;
                vec[j]->val = val;
                break;
            }
        }
    }
};