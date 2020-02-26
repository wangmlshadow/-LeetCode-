#include "normal.h"

/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*/

class Solution {     // ĳһ��������ˮ�����ڴ˸����ұ߽��н�Сֵ��ȥ�ø�߶ȣ�˫ָ�뷨����Ŀ�������������������ַ���
public:
    int trap(vector<int>& height) {
        int left = 0, right = 0;
        int left_id = 0, right_id = height.size() - 1;
        int total = 0;

        while (left_id < right_id) {
            if (height[left_id] <= height[right_id]) {
                if (left <= height[left_id])
                    left = height[left_id];
                else
                    total += (left - height[left_id]);

                left_id++;
            }
            else {
                if (right <= height[right_id])
                    right = height[right_id];
                else
                    total += (right - height[right_id]);

                right_id--;
            }
        }

        return total;
    }
};