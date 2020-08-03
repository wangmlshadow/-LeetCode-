#include "normal.h"

/*
��̬�滮

����һ���������飬������������Ҳ�и����������е�һ������������������һ�������顣������������ĺ͵����ֵ��

Ҫ��ʱ�临�Ӷ�ΪO(n)��
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int tmp1 = nums[0], tmp2 = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            tmp1 = max(tmp1 + nums[i], nums[i]);
            tmp2 = max(tmp1, tmp2);
        }

        return tmp2;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��48 ms, ������ C++ �ύ�л�����77.19%���û�
�ڴ����ģ�23.1 MB, ������ C++ �ύ�л�����44.80%���û�
*/