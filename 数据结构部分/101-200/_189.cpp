#include "normal.h"

/*
����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        if (k == 0)
            return;

        vector<int> helper;

        for (int i = size - k; i < size; i++)
            helper.push_back(nums[i]);

        for (int i = size - 1; i >= k; i--)
            nums[i] = nums[i - k];

        for (int i = 0; i < k; i++)
            nums[i] = helper[i];
    }
};

// ������ʹ�����η�ת