#include "normal.h"

/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ��λ�á�
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {     // ��ĳ��λ�ÿ��Ե������λ��֮ǰ����Щ�ɵ����λ��������һ����ʾ����Ծ������ڵ�������λ��֮��ľ���
        int size = nums.size();
        vector<bool> sign(size, false);
        sign[0] = true;

        for (int i = 1; i < size; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (sign[j] && i - j <= nums[j]) {
                    sign[i] = true;
                    break;
                }
            }
        }

        return sign[size - 1];
    }
};