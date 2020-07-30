#include "normal.h"

/*
����

������0��ʼ����ΪN������A������0��N - 1�������������ҵ����ļ���S���������С������ S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }���������µĹ���

����ѡ������Ϊi��Ԫ��A[i]ΪS�ĵ�һ��Ԫ�أ�S����һ��Ԫ��Ӧ����A[A[i]]��֮����A[A[A[i]]]... �Դ����ƣ��������ֱ��S�����ظ���Ԫ�ء�

˼·��1.������ĿҪ������⣬�����ʱ
      2.�Ľ���һ�ַ�����ʹ���������Ѿ��������Ļ�
      3.ֱ���޸�ԭ���飬����Ҫ�����ڴ�
*/

class Solution {   // ��ʱ ��854��������ͨ��
public:
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> have(nums.size(), 0);
            int cnt = 0, j = i;

            while (have[j] == 0) {
                have[j] = 1;
                cnt++;
                j = nums[j];
            }

            res = max(res, cnt);
        }

        return res;
    }
};

class Solution {   // �Ż� ȥ��������ظ�����
public:
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> have(nums.size(), 0);   // S����nums�и���Ԫ����ɵ�һ�������ӻ����κ�һ���㶼���Ա���������
                                            // ���������������ȣ���have�ŵ����棬�����ظ�����ͬһ����

        for (int i = 0; i < nums.size(); i++) {
            if (have[i] != 0)
                continue;

            int cnt = 0, j = i;

            while (have[j] == 0) {
                have[j] = 1;
                cnt++;
                j = nums[j];
            }

            res = max(res, cnt);
        }

        return res;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��60 ms, ������ C++ �ύ�л�����19.08%���û�
�ڴ����ģ�29.7 MB, ������ C++ �ύ�л�����25.00%���û�
*/


class Solution {   
public:
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums.size())
                continue;

            int cnt = 0, j = i, temp;

            while (nums[j] != nums.size()) {
                temp = j;
                cnt++;
                j = nums[j];
                nums[temp] = nums.size();
            }

            res = max(res, cnt);
        }

        return res;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��32 ms, ������ C++ �ύ�л�����91.60%���û�
�ڴ����ģ�29.4 MB, ������ C++ �ύ�л�����25.00%���û�
*/