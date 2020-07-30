#include "normal.h"

/*
����

�����������飬arr1 �� arr2��

arr2 �е�Ԫ�ظ�����ͬ
arr2 �е�ÿ��Ԫ�ض������� arr1 ��
�� arr1 �е�Ԫ�ؽ�������ʹ arr1 ��������˳��� arr2 �е����˳����ͬ��δ�� arr2 �г��ֹ���Ԫ����Ҫ����������� arr1 ��ĩβ��

*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> another;   // δ��arr2�г��ֵ�
        map<int, int> m;       // ������arr2�е�

        set<int> s;
        for (auto n : arr2)
            s.insert(n);

        for (auto n : arr1) {
            if (s.find(n) != s.end())
                m[n]++;
            else
                another.push_back(n);
        }

        vector<int> res;

        for (auto n : arr2) {
            for (int i = 0; i < m[n]; i++)
                res.push_back(n);
        }

        sort(another.begin(), another.end());
        res.insert(res.end(), another.begin(), another.end());

        return res;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��16 ms, ������ C++ �ύ�л�����10.27%���û�
�ڴ����ģ�8.2 MB, ������ C++ �ύ�л�����9.52%���û�
*/