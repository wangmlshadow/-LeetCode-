#include "normal.h"

/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/single-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {    // ��֤����ʱ�临�ӶȺͲ�ʹ�ö���ռ� ʹ��������
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (auto i : nums)
            res ^= i;

        return res;
    }
};

class Solution {    // ��֤����ʱ�临�ӶȺͲ�ʹ�ö���ռ� ʹ��������
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int res = 0;

        for (int i = 0; i < size; i++)
            res ^= nums[i];

        return res;
    }
};