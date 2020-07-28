#include "normal.h"

/*
����

����һ���������� arr���������Ƿ������������ N �� M������ N �� M ������������N = 2 * M����

����ʽ�أ�����Ƿ���������±� i �� j ���㣺

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

˼·��1.ʹ��set��ע�ⵥ������0
      2.��������˫��ѭ��
      3.����˫ָ��
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> myS;
        int cntZero = 0;

        for (int num : arr)
            if (num != 0)
                myS.insert(num);
            else
                cntZero++;

        if (cntZero >= 2)
            return true;

        for (int num : arr) {
            if (myS.find(num * 2) != myS.end())
                return true;
        }

        return false;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��16 ms, ������ C++ �ύ�л�����20.52%���û�
�ڴ����ģ�8.4 MB, ������ C++ �ύ�л�����100.00%���û�
*/