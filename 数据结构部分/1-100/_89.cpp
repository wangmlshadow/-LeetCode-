#include "normal.h"

/*
���ױ�����һ������������ϵͳ���ڸ�ϵͳ�У�������������ֵ����һ��λ���Ĳ��졣

����һ�����������λ���ķǸ����� n����ӡ����ױ������С����ױ������б����� 0 ��ͷ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/gray-code
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {    // ��n - 1 �����Ƶ��� n�� ��0��n
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        int head = 1;

        for (int i = 0; i < n; i++) {
            for (int j = result.size() - 1; j >= 0; j--) 
                result.push_back(result[j] + head);

            head <<= 1;
        }

        return result;
    }
};