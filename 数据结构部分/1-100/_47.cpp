#include "normal.h"

/*
����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            reproduce(result, nums[i]);
        }

        sort(result.begin(), result.end());   // �������ȥ���ظ���ȡ�ɷ�ʽ�����бȽ���
        vector<vector<int>> temp;

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                temp.push_back(result[i]);
                continue;
            }
                
            if (result[i - 1] != result[i])
                temp.push_back(result[i]);
        }

        return temp;
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

                while (j < type - 1 && num == cur[j]) {   // ��ֹ�ظ������ǲ���ȥ�������ظ�
                    j++;
                }

                cur.insert(cur.begin() + j, num);
                temp.push_back(cur);
            }
        }

        result = temp;
    }
};