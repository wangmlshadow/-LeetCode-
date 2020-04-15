#include "normal.h"

/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ�Χ��һȦ������ζ
�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ
���ϱ�С͵���룬ϵͳ���Զ�������
����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/house-robber-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;

        if (size == 1)
            return nums[0];

        if (size == 2)
            return max(nums[0], nums[1]);

        vector<int> dp_1(size, 0);
        dp_1[0] = nums[0];
        dp_1[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < size - 1; i++) {
            dp_1[i] = max(dp_1[i - 1], dp_1[i - 2] + nums[i]);
        }

        vector<int> dp_2(size, 0);
        dp_2[size - 1] = nums[size - 1];
        dp_2[size - 2] = max(nums[size - 1], nums[size - 2]);

        for (int i = size - 3; i > 0; i--) {
            dp_2[i] = max(dp_2[i + 1], dp_2[i + 2] + nums[i]);
        }

        return max(dp_1[size - 2], dp_2[1]);
    }
};

/*
ִ����ʱ :
0 ms, ������ C++ �ύ�л�����100.00%���û�
�ڴ����� :
7.8 MB, ������ C++ �ύ�л�����100.00%���û�
*/
