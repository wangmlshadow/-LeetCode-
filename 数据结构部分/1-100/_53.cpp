#include "normal.h"

/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }

        int temp_1 = nums[0], temp_2 = nums[0];

        for (int i = 1; i < size; i++) {
            temp_2 = max(nums[i], temp_2 + nums[i]);
            temp_1 = max(temp_1, temp_2);
        }

        return temp_1;
    }
};