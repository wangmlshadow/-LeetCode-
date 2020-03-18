#include "normal.h"

/*
����һ������ n������������ 1 ... n Ϊ�ڵ�����ɵĶ�����������
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
    vector<TreeNode*> generateTrees(int n) {   
        vector<TreeNode*> result;
        if (n == 0)
            return result;
        
        return gen(1, n);
    }

private:
    vector<TreeNode*> gen(int start, int end) {
        vector<TreeNode*> res;

        if (start > end)
            res.push_back(NULL);

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = gen(start, i - 1);
            vector<TreeNode*> right = gen(i + 1, end);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};