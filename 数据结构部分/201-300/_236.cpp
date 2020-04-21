#include "normal.h"

/*
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾ
Ϊһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ���
���ȣ�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> tra;
        vector<TreeNode*> pS;
        vector<TreeNode*> qS;
        TreeNode* last = NULL;
        TreeNode* point = root;
        int cnt = 0;

        while (point != NULL || !tra.empty()) {
            if (point != NULL) {
                tra.push_back(point);
                point = point->left;
            }
            else {
                point = *tra.rbegin();

                if (point->right != NULL && point->right != last) {
                    point = point->right;
                }
                else {
                    if (point == p) {
                        pS = tra;
                        cnt++;

                        if (cnt == 2)
                            break;
                    }

                    if (point == q) {
                        qS = tra;
                        cnt++;

                        if (cnt == 2)
                            break;
                    }

                    tra.pop_back();
                    last = point;
                    point = NULL;
                }
            }
        }

        TreeNode* res = root;

        for (int i = 0; i < pS.size() && i < qS.size(); i++) {
            if (pS[i] != qS[i])
                break;

            res = pS[i];
        }

        return res;
    }
};