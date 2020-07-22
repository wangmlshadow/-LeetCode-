#include "normal.h"

/*
����

����һ���������飬������������֮��ĵ� k ����С���롣һ�� (A, B) �ľ��뱻����Ϊ A �� B ֮��ľ��Բ�ֵ��
*/

class Solution {  // ����֮����� �����Ӧ�����Ը���    ����  Ѱ��k
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = *nums.rbegin() - *nums.begin();  // ����֮���������ֵ����Сֵ

        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0, left = 0;

            for (int right = 0; right < nums.size(); right++) {
                while (nums[right] - nums[left] > mid)
                    left++;

                count += right - left;  // ����С��
            }

            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};