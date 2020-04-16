#include "normal.h"

/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> helper;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            set<int>::iterator iter = helper.find(nums[i]);

            if (iter != helper.end())
                return true;
            else
                helper.insert(nums[i]);
        }
        
        return false;
    }
};