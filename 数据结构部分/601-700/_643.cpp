#include "normal.h"

/*
����

���� n ���������ҳ�ƽ��������ҳ���Ϊ k �����������飬����������ƽ������

˼·����������
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = 0, nowSum = 0;

        if (k > nums.size())
            return 0;

        for (int i = 0; i < k; i++) {
            nowSum += nums[i];
        }
        
        maxSum = nowSum;

        for (int i = k; i < nums.size(); i++) {
            nowSum += (nums[i] - nums[i - k]);
            maxSum = max(maxSum, nowSum);
        }

        return maxSum / double(k);
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��292 ms, ������ C++ �ύ�л�����74.32%���û�
�ڴ����ģ�71.5 MB, ������ C++ �ύ�л�����25.00%���û�
*/