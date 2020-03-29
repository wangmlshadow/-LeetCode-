#include "normal.h"

/*

�����������ʣ�beginWord �� endWord����һ���ֵ䣬�ҵ��� beginWord �� endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У����� 0��
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
            return 0;

        queue<item> save;
        unordered_map<string, int> allSave;
        //unordered_map<string, vector<string>> reflex;
        bool findEnd = false;
        save.push(item(beginWord, 1));
        allSave.insert(pair<string, int>(beginWord, 1));
        int size = wordList.size();

        while (!save.empty()) {
            item now = save.front();
            save.pop();

            if (now.str == endWord) {
                return allSave[endWord];
            }

            for (int i = 0; i < size; i++) {
                if (match(now.str, wordList[i])) {
                    if (allSave.find(wordList[i]) == allSave.end()) {
                        save.push(item(wordList[i], now.deep + 1));
                        allSave.insert(pair<string, int>(wordList[i], now.deep + 1));
                        //reflex[wordList[i]].push_back(now.str);
                    }
                }
            }
        }

        return 0;

    }

    struct item {
        string str;
        int deep;
        item(string s, int d) : str(s), deep(d) {}
    };

    bool match(string& s1, string& s2) {
        int cnt = 0;
        int len = s1.length();

        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i])
                cnt++;

            if (cnt > 1)
                return false;
        }

        return cnt <= 1;
    }
};