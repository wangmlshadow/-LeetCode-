#include "normal.h"

/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int cnt = 1;
        int ahead = nums[0], cur = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (ahead != nums[i]) {
                nums[cur] = nums[i];
                ahead = nums[i];
                cur++;
                cnt++;
            }
        }

        return cnt;
    }
};