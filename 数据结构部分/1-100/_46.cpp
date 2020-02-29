#include "normal.h"

/*
����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�
*/

class Solution {  
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            reproduce(result, nums[i]);
        }

        return result;
    }

    void reproduce(vector<vector<int>>& result, int num) {     // �ڸ�����һ���������ٲ���һ�����֣������������н��ͨ��result����
        if (result.empty()) {
            result.push_back({ num });
            return;
        }
        
        int type = result[0].size() + 1;     // ��Ϊn�����ֶ��в���һ�����֣����Բ���n+1�ֽ��
        vector<vector<int>> temp;

        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < type; j++) {
                vector<int> cur = result[i];
                cur.insert(cur.begin() + j, num);
                temp.push_back(cur);
            }
        }

        result = temp;
    }
};      // ���н����ʾ����ܿ�