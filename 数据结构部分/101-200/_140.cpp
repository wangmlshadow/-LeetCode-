# include "normal.h"

/*
����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict�����ַ��������ӿո�������һ�����ӣ�ʹ�þ��������еĵ��ʶ��ڴʵ��С�����������Щ���ܵľ��ӡ�

˵����

�ָ�ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-break-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {    // ����֤�Ƿ��ܲ�־ͻᳬʱ ��֤�˾Ͳ���ʱ
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.length();
        size = wordDict.size();

        if (size == 0 || len == 0)
            return {};

        vector<string> res;
        maxLen = wordDict[0].length();
        minLen = wordDict[0].length();

        for (int i = 1; i < size; i++) {
            if (maxLen < wordDict[i].length())
                maxLen = wordDict[i].length();

            if (minLen > wordDict[i].length())
                minLen = wordDict[i].length();
        }


        vector<vector<bool>> helper(len, vector<bool>(len, false));  // helper[i][j]�ж�s���Ӵ�i-j�Ƿ���wordDict�г���

        for (int j = 0; j < len; j++) {
            for (int i = 0; i <= j; i++) {
                int subLen = j - i + 1;

                if (subLen < minLen || subLen > maxLen)
                    continue;
                else {
                    vector<string>::iterator key = find(wordDict.begin(), wordDict.end(), s.substr(i, subLen));
                    helper[i][j] = key != wordDict.end();
                }
            }
        }

        vector<bool> dp(len, false);

        for (int i = 0; i < len; i++) {
            if (i == 0) {
                dp[i] = helper[i][i];
                continue;
            }

            bool sign = helper[0][i];

            for (int j = 0; j <= i; j++) {
                sign = sign || (dp[j] && helper[j + 1][i]);

                if (sign)
                    break;
            }

            dp[i] = sign;
        }

        if (!dp[len - 1])  // ��֤�Ƿ��ܲ��
            return {};

        addRes(helper, s, 0, minLen, "", res);
        return res;
    }

private:
    int len;
    int size;
    int maxLen;
    int minLen;

    void addRes(vector<vector<bool>>& helper, string& s, int begin, int cnt, string one, vector<string>& res) {
        if (cnt > maxLen)
            return;

        if (begin + cnt == len) {
            if (helper[begin][begin + cnt - 1])
                res.push_back(one + s.substr(begin, cnt));

            return;
        }
        else if (begin + cnt > len)
            return;
        else {
            if (helper[begin][begin + cnt - 1]) {
                addRes(helper, s, begin + cnt, minLen, one + s.substr(begin, cnt) + " ", res);
            }
            addRes(helper, s, begin, cnt + 1, one, res);
        }
    }
};