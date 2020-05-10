#include "normal.h"

/*
����һ����������  nums�������������� i �� j  (i �� j) ��Χ��Ԫ�ص��ܺͣ����� i,  j ���㡣
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;

        for (auto num : nums) {
            sum += num;
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];

        return sums[j] - sums[i - 1];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */