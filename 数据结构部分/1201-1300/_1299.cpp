#include "normal.h"

/*
����

����һ������ arr �����㽫ÿ��Ԫ�������ұ�����Ԫ���滻����������һ��Ԫ�أ��� -1 �滻��

��������滻���������㷵��������顣

˼·���Ӻ���ǰ�����滻 ʹ��rep�����ʱ�����ֵ��Ҳ�������滻��ֵ
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty())
            return arr;

        int rep = arr[arr.size() - 1];   // �����滻����
        arr[arr.size() - 1] = -1;

        for (int i = arr.size() - 2; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = rep;
            rep = max(rep, temp);
        }

        return arr;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��36 ms, ������ C++ �ύ�л�����39.34%���û�
�ڴ����ģ�14 MB, ������ C++ �ύ�л�����7.14%���û�
*/