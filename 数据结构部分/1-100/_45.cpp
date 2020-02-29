#include "normal.h"

/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/jump-game-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int pos = 0;
        int end = nums.size() - 1;

        if (end == 0)
            return 0;

        for (int i = 0; i <= end; ) {
            if (pos + nums[i] >= end) {
                return ++step;
            }

            int max = 1;
            for (int j = 2; j <= nums[i]; j++) {     // Ѱ�ұ�����Ծ��������´���Ծ��������ֵ
                if (max + nums[i + max] < j + nums[i + j])
                    max = j;
            }

            i += max;
            pos = i;
            step++;
        }

        return step;
    }
};