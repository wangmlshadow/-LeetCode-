#include "normal.h"

/*
����

����һ��ֱ��ͼ(Ҳ����״ͼ)���������˴�����ԴԴ���ϵص�ˮ�����ֱ��ͼ�ܴ����ˮ��?ֱ��ͼ�Ŀ��Ϊ 1��

˼·��˫ָ�뷨
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                res += leftMax - height[left++];
                leftMax = max(leftMax, height[left]);
            }
            else {
                res += rightMax - height[right--];
                rightMax = max(rightMax, height[right]);
            }
        }

        return res;
    }
};
