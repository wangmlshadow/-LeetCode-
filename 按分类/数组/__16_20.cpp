#include "normal.h"

/*
����
 
����ʽ�ֻ��ϣ��û�ͨ�����ּ������룬�ֻ����ṩ����Щ������ƥ��ĵ����б�ÿ������
ӳ�䵽0��4����ĸ������һ���������У�ʵ��һ���㷨������ƥ�䵥�ʵ��б����õ�һ��
������Ч���ʵ��б�ӳ������ͼ��ʾ��

˼·�������޳�������Ҫ��ĵ���
*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {      
        if (num.find('1') != num.npos || num.find('0') != num.npos)  // ��������1 ��������0 �ǲ��������Ч���ʵ�
            return vector<string>();

        vector<string> res(words);

        for (int i = 0; i < num.length(); i++) {
            if (res.empty())
                return res;

            vector<string> cur;
            int n = num[i] - '0';

            for (int j = 0; j < res.size(); j++) {
                if (res[j].length() <= i)
                    continue;

                if (matched(n, res[j][i]))
                    cur.push_back(res[j]);
            }

            res = cur;
        }

        return res;
    }

    bool matched(int n, char ch) {
        if (n == 2) {
            if (ch == 'a' || ch == 'b' || ch == 'c')
                return true;
            else
                return false;
        }

        if (n == 3) {
            if (ch == 'd' || ch == 'e' || ch == 'f')
                return true;
            else
                return false;
        }

        if (n == 4) {
            if (ch == 'g' || ch == 'h' || ch == 'i')
                return true;
            else
                return false;
        }

        if (n == 5) {
            if (ch == 'j' || ch == 'k' || ch == 'l')
                return true;
            else
                return false;
        }

        if (n == 6) {
            if (ch == 'm' || ch == 'n' || ch == 'o')
                return true;
            else
                return false;
        }

        if (n == 7) {
            if (ch == 'p' || ch == 'q' || ch == 'r' || ch == 's')
                return true;
            else
                return false;
        }

        if (n == 8) {
            if (ch == 't' || ch == 'u' || ch == 'v')
                return true;
            else
                return false;
        }

        if (n == 9) {
            if (ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z')
                return true;
            else
                return false;
        }

        return false;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��208 ms, ������ C++ �ύ�л�����7.98%���û�
�ڴ����ģ�235.6 MB, ������ C++ �ύ�л�����100.00%���û�
*/