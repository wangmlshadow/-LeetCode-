#include "normal.h"

/*
�����������ʣ�beginWord �� endWord����һ���ֵ� wordList���ҳ����д� beginWord �� endWord �����ת�����С�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У�����һ�����б�
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-ladder-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == "" || endWord == "" || wordList.empty())
            return {};

        queue<item> save;
        unordered_map<string, int> allSave;
        unordered_map<string, vector<string>> reflex;
        vector<vector<string>> allPath;
        bool findEnd = false;
        save.push(item(beginWord, 1));
        allSave.insert(pair<string, int>(beginWord, 1));
        int size = wordList.size();

        while (!save.empty()) {
            item now = save.front();
            save.pop();

            if (now.str == endWord) {
                findEnd = true;
                break;
            }

            for (int i = 0; i < size; i++) {
                if (match(now.str, wordList[i])) {
                    if (allSave.find(wordList[i]) == allSave.end()) {
                        save.push(item(wordList[i], now.deep + 1));
                        allSave.insert(pair<string, int>(wordList[i], now.deep + 1));
                        reflex[wordList[i]].push_back(now.str);
                    }
                    else {
                        if (allSave[wordList[i]] <= now.deep)
                            continue;
                        else
                            reflex[wordList[i]].push_back(now.str);
                    }                             
                }
            }
        }

        if (!findEnd)
            return {};

        dfs(beginWord, endWord, reflex, {}, allPath);

        return allPath;
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

    void dfs(string& beginWord, string toTrace, unordered_map<string, vector<string>>& reflex, vector<string> path, vector<vector<string>>& allPath) {
        if (toTrace == beginWord) {
            path.push_back(toTrace);
            reverse(path.begin(), path.end());
            allPath.push_back(path);
            return;
        }

        path.push_back(toTrace);

        for (auto& i : reflex[toTrace])    // end->begin
            dfs(beginWord, i, reflex, path, allPath);
    }
};