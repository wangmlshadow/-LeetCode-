#include "normal.h"

/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int cnt = nums.size();

        for (int i = 0; i < cnt; i++) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }

        for (; cur < cnt; cur++)
            nums[cur] = 0;
    }
};