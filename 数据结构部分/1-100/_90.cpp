#include "normal.h"

/*
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int cnt = 1;
            while (i < size - 1 && nums[i + 1] == nums[i]) {
                i++;
                cnt++;
            }
            Append(result, nums[i], cnt);
        }

        
        return result;
    }

    void Append(vector<vector<int>>& result, int n, int cnt) {
        int size = result.size();

        for (int i = 0; i < size; i++) {
            vector<int> temp = result[i];
            
            for (int j = 0; j < cnt; j++) {
                temp.push_back(n);
                result.push_back(temp);
            }
        }
    }
};