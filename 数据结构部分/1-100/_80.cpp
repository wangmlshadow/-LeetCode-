#include "normal.h"

/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int end = 0;
        int size = nums.size();

        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[end]) {
                if (i - end == 1)
                    end++;
                else
                    nums[++end] = nums[i];
            }
            else {
                if (end == 0)
                    end++;
                else {
                    if (nums[end - 1] != nums[i]) {
                        if (i - end == 1)
                            end++;
                        else
                            nums[++end] = nums[i];
                    }
                }
            }
        }

        return end + 1;
    }
};