#include "normal.h"

/*
�������ȷֱ�Ϊ?m?��?n?���������飬��Ԫ����?0-9?���ɣ���ʾ������Ȼ����λ�ϵ����֡�����
��������������ѡ�� k (k <= m + n)?������ƴ�ӳ�һ���µ�����Ҫ���ͬһ��������ȡ������
�ֱ�������ԭ�����е����˳��

���������������������������һ����ʾ��������ĳ���Ϊ?k?�����顣

˵��: �뾡���ܵ��Ż����㷨��ʱ��Ϳռ临�Ӷȡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/create-maximum-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int n = nums1.size(), m = nums2.size();

        for (int s = max(0, k - m); s <= min(k, n); s++) {
            vector<int> temp;
            int i = 0, j = 0;
            vector<int> temp1 = maxKSeq(nums1, s);
            vector<int> temp2 = maxKSeq(nums2, k - s);
            auto iter1 = temp1.begin(), iter2 = temp2.begin();

            while (iter1 != temp1.end() || iter2 != temp2.end())  // �鲢
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);

            res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
        }

        return res;
    }

    vector<int> maxKSeq(vector<int>& v, int k) {
        int n = v.size();

        if (n <= k)
            return v;

        vector<int> res;
        int pop = n - k;

        for (int i = 0; i < n; i++) {
            while (!res.empty() && v[i] > res.back() && pop-- > 0)
                res.pop_back();
            res.push_back(v[i]);
        }

        res.resize(k);
        return res;
    }
};