#include "normal.h"

/*

����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�

˵����

���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
*/

class Solution {   // �ݹ鳬ʱ
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        len = s.length();

        if (len == 0)
            return true;

        return solution(s, 0, 1, wordDict);
    }
private:
    int len;

    bool solution(string& s, int begin, int cnt, vector<string>& wordDict) {
        if (begin + cnt == len) {
            vector<string>::iterator key = find(wordDict.begin(), wordDict.end(), s.substr(begin, cnt));

            return key != wordDict.end();
        }
        else if (begin + cnt < len) {
            vector<string>::iterator key = find(wordDict.begin(), wordDict.end(), s.substr(begin, cnt));

            if (key == wordDict.end())
                return solution(s, begin, cnt + 1, wordDict);
            else
                return solution(s, begin + cnt, 1, wordDict) || solution(s, begin, cnt + 1, wordDict);
        }
        else
            return false;
    }
};

// ���Զ�̬�滮     �������ͨ�� û�г�ʱ
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {   // ��֪���߷ǿ� ���ǲ���������Ϊ�յġ�����
        int len = s.length();
        int size = wordDict.size();

        if (size == 0)
            return len == 0;

        int maxLen = wordDict[0].length();
        int minLen = wordDict[0].length();

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

        return dp[len - 1];
    }
};