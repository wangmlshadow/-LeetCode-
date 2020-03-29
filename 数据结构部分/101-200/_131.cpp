#include "normal.h"

/*
����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���

���� s ���п��ܵķָ����
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        len = s.length();
        

        if (len == 0)
            return res;

        vector<string> strs;

        solution(s, strs, 0, 1);

        return res;
    }

private:
    int len;
    vector<vector<string>> res;

    bool isStr(string& s, int begin, int end) {   // �ж�ָ����Χ���Ӵ��Ƿ�Ϊ�����Ӵ�
        while (begin < end) {
            if (s[begin] != s[end])
                return false;
            
            begin++;
            end--;
        }

        return true;
    }

    void solution(string& s, vector<string> strs, int begin, int cnt) {
        if (begin >= len || begin + cnt > len)
            return;

        if (begin + cnt == len) {
            if (isStr(s, begin, begin + cnt - 1)) {
                vector<string> cur = strs;
                cur.push_back(s.substr(begin, cnt));
                res.push_back(cur);
                return;
            }
            else
                return;
        }

        if (isStr(s, begin, begin + cnt - 1)) {
            vector<string> cur = strs;
            cur.push_back(s.substr(begin, cnt));
            solution(s, cur, begin + cnt, 1);
        }

        solution(s, strs, begin, cnt + 1);
    }
};


// �ܲ����ö�̬�滮��   ���� 

// ����
