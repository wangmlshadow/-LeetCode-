#include "normal.h"

/*
����һ����������飬�ҳ�����������֮������Ԫ��֮�����Ĳ�ֵ��

�������Ԫ�ظ���С�� 2���򷵻� 0��


����Լ�������������Ԫ�ض��ǷǸ�����������ֵ�� 32 λ�з���������Χ�ڡ�
�볢��������ʱ�临�ӶȺͿռ临�Ӷȵ������½�������⡣
*/


class Solution {   // ����ͨ��
public:
    int maximumGap(vector<int>& nums) {
        // ����������ʱ�临�Ӷ�
        int size = nums.size();

        if (size < 2)
            return 0;

        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];

        for (int i = 2; i < size; i++) {
            if (nums[i] - nums[i - 1] > res)
                res = nums[i] - nums[i - 1];
        }

        return res;
    }
};



class Solution {    // Ͱ�͸���ԭ��
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();

        if (size < 2)
            return 0;

        int minVal = nums[0];
        int maxVal = nums[0];

        for (int i = 1; i < size; i++) {
            if (nums[i] < minVal)
                minVal = nums[i];
            
            if (nums[i] > maxVal)
                maxVal = nums[i];
        }

        if (minVal == maxVal)
            return 0;

        int gap = (maxVal - minVal + size - 1) / (size - 1);

        vector<int> mins(size - 1, maxVal);
        vector<int> maxs(size - 1, minVal);

        for (int i = 0; i < size; i++) {
            if (nums[i] == minVal || nums[i] == maxVal)
                continue;

            int index = (nums[i] - minVal) / gap;

            if (nums[i] < mins[index])
                mins[index] = nums[i];

            if (nums[i] > maxs[index])
                maxs[index] = nums[i];
        }

        int res = 0;
        int preMax = minVal;

        for (int i = 0; i < size - 1; i++) {
            if (mins[i] == maxVal)
                continue;

            res = max(res, mins[i] - preMax);
            preMax = maxs[i];
        }

        return max(res, maxVal - preMax);
    }
};

