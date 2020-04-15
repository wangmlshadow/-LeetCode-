#include "normal.h"

/*
��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // set<int> topK; // set����Ԫ�ز����ظ�
        int size = nums.size();
        multiset<int> topK;

        for (int i = 0; i < k; i++) {
            topK.insert(nums[i]);
        }

        for (int i = k; i < size; i++) {
            if (*topK.begin() < nums[i]) {
                topK.erase(topK.begin());
                topK.insert(nums[i]);
            }
        }

        return *topK.begin();
    }
};