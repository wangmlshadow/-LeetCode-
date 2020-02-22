#include "normal.h"

/*
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/next-permutation
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {    // �ر�죬�������ڴ�Ҳ��
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = nums.size();

        if (cnt < 2)
            return;

        int i;

        for (i = cnt - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1])
                break;
        }

        if (i == 0) {
            for (i = 0; i < cnt / 2; i++) {
                int temp = nums[i];
                nums[i] = nums[cnt - i - 1];
                nums[cnt - i - 1] = temp;
            }

            return;
        }

        int pos = i - 1;   // ��Ҫ���޸ĵĿ�ʼλ��
        int k = i++;

        for (; i < nums.size(); i++) {
            if (nums[i] > nums[pos] && nums[i] < nums[k])
                k = i;
        }

        int temp = nums[pos];
        nums[pos] = nums[k];
        nums[k] = temp;

        sort(nums.begin() + pos + 1, nums.end());

        return;
    }
};

