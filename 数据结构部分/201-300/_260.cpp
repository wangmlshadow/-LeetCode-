#include "normal.h"

/*
����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> s;
        int cnt = nums.size();

        if (cnt == 0)
            return {};

        for (int i = 0; i < cnt; i++) {
            if (s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else
                s.erase(nums[i]);
        }

        vector<int> res;
        res.push_back(*s.begin());
        res.push_back(*s.rbegin());
        return res;
    }
};