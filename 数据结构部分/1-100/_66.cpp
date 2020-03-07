#include "normal.h"

/*
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/plus-one
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int plus = 1;
        int i;

        for (i = digits.size() - 1; i >= 0; i--) {
            plus += digits[i];

            if (plus > 9) {
                result.push_back(plus % 10);
                plus = 1;
            }
            else {
                result.push_back(plus);
                plus = 0;
            }
        }

        if (plus == 1) {
            result.push_back(plus);
        }

        int len = result.size();
        for (i = 0; i < len / 2; i++) {
            int temp = result[i];
            result[i] = result[len - 1 - i];
            result[len - 1 - i] = temp;
        }

        return result;
    }
};