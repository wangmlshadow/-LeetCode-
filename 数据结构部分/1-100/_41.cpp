#include "normal.h"

/*
����һ��δ������������飬�ҳ�����û�г��ֵ���С����������
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int sign = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                sign++;
                break;
            }
        }

        if (sign == 0)   // û��1
            return 1;

        if (size == 1)   // ������һ��if�жϳ���1����nums�н���һ��Ԫ��
            return 2;

        // �����и�����0���Լ�����size������Ϊ1
        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0 || nums[i] > size)
                nums[i] = 1;
        }

        // Ҫ�����ռ�ΪO(1)���������鱾��Ĵ洢�ռ�
        for (int i = 0; i < size; i++) {
            int temp = abs(nums[i]);

            if (temp == size)
                nums[0] = -abs(nums[0]);
            else
                nums[temp] = -abs(nums[temp]);
        }

        for (int i = 1; i < size; i++) {
            if (nums[i] > 0)
                return i;
        }

        if (nums[0] > 0)
            return size;         // numsΪ1.....n-1
        else
            return size + 1;     // numsΪ1.......n
    }
};