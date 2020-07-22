#include "normal.h"

/*
����

����һ�������ַ������ֵ����飬�ҵ���������飬�Ұ������ַ������ֵĸ�����ͬ��

���ظ������飬�����ڶ��������飬������˵���С�ġ������������������飬����һ�������顣
*/

class Solution {    // ���� ���ǳ�ʱ
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int size = array.size();
        vector<vector<int>> cnts(size + 1, vector<int>(2, 0));  // cnts[n + 1]��¼array��ǰn���ַ������֡��ַ�������

        for (int i = 0; i < size; i++) {
            if (isdigit(array[i][0])) {
                cnts[i + 1][0] = cnts[i][0] + 1;
                cnts[i + 1][1] = cnts[i][1];
            }
            else {
                cnts[i + 1][0] = cnts[i][0];
                cnts[i + 1][1] = cnts[i][1] + 1;
            }
        }

        int resL = 0, maxLen = 0;

        for (int i = 0; i < size; i++) {
            for (int j = size - 1; j > i; j--) {
                if (cnts[j + 1][0] - cnts[i][0] == cnts[j + 1][1] - cnts[i][1]) {  // �ִ� i-j
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        resL = i;
                    }
                    break;   // ��i��ͷ������������ִ��Ѿ������� ����Ҫ�����ڲ����ѭ��
                }
            }
        }

        if (maxLen == 0) {
            return vector<string>();
        }

        vector<string> res;
        res.insert(res.end(), array.begin() + resL, array.begin() + resL + maxLen);
        return res;
    }
};

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<int> num(array.size() + 1, 0);

        for (int i = 0; i < array.size(); i++) {
            if (isdigit(array[i][0]))
                num[i + 1] = num[i] + 1;
            else
                num[i + 1] = num[i] - 1;
        }

        map<int, int> m;
        int ans = 0, start = 0, end = 0;

        for (int i = 1; i <= array.size(); i++) {
            if (num[i] != 0 && m[num[i]] == 0)
                m[num[i]] = i;
            else {
                if (ans < i - m[num[i]]) {
                    ans = i - m[num[i]];
                    start = m[num[i]] + 1;
                    end = i;
                }
            }
        }

        if (ans == 0)
            return vector<string>();

        vector<string> res;
        res.insert(res.end(), array.begin() + start - 1, array.begin() + end);
        return res;
    }
};