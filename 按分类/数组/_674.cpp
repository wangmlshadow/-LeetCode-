#include "normal.h"

/*
����

����һ��δ��������������飬�ҵ���������ĵĵ������У������ظ����еĳ��ȡ�

˼·����ǰ���ɨ�裬Ѱ�ҵ�������
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int res = 1, cur = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                cur++;
            else {
                res = max(res, cur);
                cur = 1;
            }
        }

        return max(res, cur);
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��24 ms, ������ C++ �ύ�л�����40.53%���û�
�ڴ����ģ�10.8 MB, ������ C++ �ύ�л�����6.67%���û�
*/