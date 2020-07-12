#include "normal.h"

/*
1343. ��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ   ����
����һ���������� arr ���������� k �� threshold ��

���㷵�س���Ϊ k ��ƽ��ֵ���ڵ��� threshold ����������Ŀ��

˼·��
    ��������
    Ѱ�Ҿ�ֵ���ڵ���threshold�ҳ���Ϊk�������飬ʹ��cur_sum�洢��ʱ���ڲ�����������ĺ�     
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // ���������� ע������
        if (k > arr.size())
            return 0;

        int res = 0;
        long long sum = k * threshold, cur_sum = 0;
        int i = 0;

        for (; i < k; i++)
            cur_sum += arr[i];

        if (cur_sum >= sum)
            res++;

        for (; i < arr.size(); i++) {
            cur_sum = cur_sum - arr[i - k] + arr[i];  // ��ǰ��������Ԫ�صĺ͵���ǰһ�����ںͼ�ȥǰһ�����ڵ�һ��Ԫ�أ�������������������һ��ֵ

            if (cur_sum >= sum)
                res++;
        }

        return res;
    }
};

/*
ִ�н����
ͨ��
��ʾ����
ִ����ʱ��188 ms, ������ C++ �ύ�л�����94.68%���û�
�ڴ����ģ�52.5 MB, ������ C++ �ύ�л�����100.00%���û�
*/