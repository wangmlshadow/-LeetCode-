#include "normal.h"

/*
����һ������ 0, 1, 2, ..., n �� n ���������У��ҳ� 0 .. n ��û�г����������е��Ǹ�����
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        long long cnt = nums.size();

        for (int i = 0; i < cnt; i++) {
            sum += nums[i];
        }

        return ((1 + cnt) * cnt) / 2 - sum;
    }
};