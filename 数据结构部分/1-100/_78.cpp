#include "normal.h"

/*

����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int start = 0;
        vector<int> result;
        solution(nums, result, 0);
        return results;
    }

private:
    vector<vector<int>> results;

    void solution(vector<int>& nums, vector<int> result, int start) {
        results.push_back(result);

        for (int i = start; i < nums.size(); i++) {
            vector<int> temp = result;
            temp.push_back(nums[i]);
            solution(nums, temp, i + 1);
        }
    }
};