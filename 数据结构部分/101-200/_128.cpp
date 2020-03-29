#include "normal.h"

/*

����һ��δ������������飬�ҳ���������еĳ��ȡ�

Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��
*/

class Solution {    // ʹ��set ����set������ ���ڲ������ظ�ֵ
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int size = nums.size();
        set<int> con;
        
        for (auto num : nums)
            con.insert(num);

        int maxCnt = 0;

        for (auto num : nums) {
            if (con.find(num - 1) == con.end()) {   // �����������Сֵ��ʼ���� �����ζ�ͬһ�����������������
                int cur = num;
                int cnt = 1;

                while (con.find(++num) != con.end())
                    cnt++;

                maxCnt = max(maxCnt, cnt);
            }
        }
            
        return maxCnt;
    }
};