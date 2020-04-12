#include "normal.h"

/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/house-robber
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;

        if (size == 1)
            return nums[0];

        if (size == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            if (dp[i - 1] == dp[i - 2])
                dp[i] = dp[i - 1] + nums[i];
            else   // ��ʾnums[i - 1]��͵��
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[size - 1];
    }
};