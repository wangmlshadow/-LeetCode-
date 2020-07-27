#include "normal.h"

/*
����

����һ�����ȹ̶����������� arr�����㽫�������г��ֵ�ÿ���㶼��дһ�飬���������Ԫ������ƽ�ơ�

ע�⣺�벻Ҫ�ڳ��������鳤�ȵ�λ��д��Ԫ�ء�

Ҫ�������������� �͵� ���������޸ģ���Ҫ�Ӻ��������κζ�����

˼·������0֮��arr�ұ�Ԫ�ػᱻ���������ҵ��������λ�����Ҷ˵�Ԫ�� Ȼ�������滻����
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int cnt = 0, end = 0;

        for ( ; end < size; end++) {
            cnt++;
            if (arr[end] == 0)
                cnt++;

            if (cnt >= size)
                break;
        }

        if (end == size - 1)
            return;

        int right = size - 1;

        if (cnt > size) {
            arr[right--] = arr[end--];
        }

        for (; end >= 0; end--) {
            arr[right--] = arr[end];

            if (arr[end] == 0)
                arr[right--] = arr[end];           
        }

        return;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��20 ms, ������ C++ �ύ�л�����45.10%���û�
�ڴ����ģ�9.9 MB, ������ C++ �ύ�л�����12.50%���û�
*/