#include "normal.h"

/*
����

����һ���Ǹ���������������Խ���һ�������е�������λ���������ܵõ������ֵ��

˼·��һ�����ĸ�λ����Խ�������Ҳ��Խ�󣬽�numÿһλ���ַֽ�洢�������У����򣬱Ƚϣ��õ����豻����������λ��

ע�⣺���ǵ����ܶ��λ�õ�����ȣ�Խ��λ�Ľϴ����ֱ�������Խ��λ�������Խ��
*/

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;  // ��numÿһλ�����ֲ𿪴洢��nums��   ��λ�����λ
        int temp = num;

        while (temp != 0) {
            nums.push_back(temp % 10);
            temp /= 10;
        }

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());   // ��С��������

        int pos = nums.size() - 1;   // ���ձ�������λ��

        while (pos > 0 && nums[pos] == sorted[pos])
            pos--;

        if (pos < 0)
            return num;

        int another = 0;

        while (nums[another] != sorted[pos])
            another++;

        nums[another] = nums[pos];
        nums[pos] = sorted[pos];

        int res = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
            res = res * 10 + nums[i];

        return res;
    }
};

/*
ִ�н��ͨ�� ��ʾ����
ִ����ʱ��4 ms, ������ C++ �ύ�л�����30.10%���û�
�ڴ����ģ�6 MB, ������ C++ �ύ�л�����100.00%���û�
*/