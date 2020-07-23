#include "normal.h"

/*
���� 

����һ�����飬������ 1 �� N ���е�������������ȱ���������֡������� O(N) ʱ����ֻ�� O(1) �Ŀռ��ҵ�������

������˳�򷵻����������־��ɡ�

˼·; ���� 1-��n ��λ�����α�����֤�Ƿ���� ���������ʱ�临�Ӷȴﲻ��O(N)

����У�1.��� 2.��� 3.ԭ��Hash 
*/

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> res;
        sort(nums.begin(), nums.end());
        int cur = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == cur)
                cur++;
            else {
                while (cur < nums[i])
                    res.push_back(cur++);
                cur++;
            }
        }

        while (cur <= n)
            res.push_back(cur++);

        return res;
    }
};


/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��120 ms, ������ C++ �ύ�л�����10.97%���û�
�ڴ����ģ�22.8 MB, ������ C++ �ύ�л�����100.00%���û�
*/