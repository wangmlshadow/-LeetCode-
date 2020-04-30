#include "normal.h"

/*
����һ��������������飬�ҵ���������������еĳ��ȡ�

����: [10,9,2,5,3,7,101,18]
���: 4
����: ��������������� [2,3,7,101]�����ĳ����� 4��
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int cnt = nums.size();

        if (cnt == 0)
            return 0;

        vector<int> dp(cnt, 1);
        
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};