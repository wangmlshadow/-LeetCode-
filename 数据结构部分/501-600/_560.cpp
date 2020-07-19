#include "normal.h"

/*
����

����һ�����������һ������ k������Ҫ�ҵ��������к�Ϊ k ��������������ĸ�����

˼·��1.��򵥵ģ���ÿһλ��ʼ�������ɸ�λ����Ϊ���������ʼλ���Ƿ���Եõ���Ϊk������������
      2.���ٱȽϴ���������ʹ��������209���ͷ����˼·   ���ָ�����ν��������
      3.�Ż�����1
*/

class Solution {  // �˷�������
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, left = 0, right = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum < k)
                continue;
            else if(sum > k) {
                while (sum >= k && left <= i) {
                    sum -= nums[left];
                    left++;

                    if (sum == k && left <= i) {  // ע��˴� ���ܳ��ַ�������������������   kΪ0�Ĵ���
                        res++;
                    }
                }
            }
            else {   // ��left��i�������������Ϊk
                res++;
                sum -= nums[left];
                left++;
            }
        }

        return res;
    }
};



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<vector<long long>> sums(nums.size(), vector<long long>(nums.size(), 0));
        int res = 0;

        sums[0][0] = nums[0];

        if (sums[0][0] == k)
            res++;

        for (int i = 1; i < nums.size(); i++) {
            sums[0][i] = sums[0][i - 1] + nums[i];

            if (sums[0][i] == k)
                res++;
        }

        for (int i = 1; i < nums.size(); i++) {   // ��ʱ
            for (int j = i; j < nums.size(); j++) {
                sums[i][j] = sums[i - 1][j] - nums[i - 1];

                if (sums[i][j] == k)
                    res++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   // ǰ׺��
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, pre = 0;

        for (auto& x : nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) res += mp[pre - k];
            mp[pre]++;
        }

        return res;
    }
};