#include "normal.h"

/*
����

����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ���
��С�����������顣��������ڷ������������������飬���� 0��
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;

        int minLen = INT_MAX;
        int start = 0;
        int end = -1;
        int val = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] >= s)
                return 1;

            val += nums[i];
            end++;

            if (val < s) {
                continue;
            }
            else {
                minLen = min(minLen, end - start + 1);                
                val -= nums[start];
                start++;

                while (val >= s) {
                    minLen = min(minLen, end - start + 1);
                    val -= nums[start];
                    start++;
                }

                if (minLen == 2) {
                    for (int j = i + 1; j < size; j++) {
                        if (nums[j] >= s)
                            return 1;
                    }
                    return 2;
                }
            }
        }

        if (minLen == INT_MAX)
            return 0;

        return minLen;
    }
};