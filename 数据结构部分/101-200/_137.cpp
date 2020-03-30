#include "normal.h"

/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/single-number-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {    // ʹ���˶���ռ�Ҳ��ͨ��
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> helper;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            map<int, int>::iterator key = helper.find(nums[i]);

            if (key == helper.end())
                helper[nums[i]] = 1;
            else {
                if (helper[nums[i]] == 1)
                    helper[nums[i]] = 2;
                else
                    helper.erase(key);
            }
        }

        return helper.begin()->first;
    }
};

// λ����
