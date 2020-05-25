#include "normal.h"

/*
����һ��������Сд��ĸ���ַ���������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸ
ֻ����һ�Ρ��豣֤���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���
*/

//  // https://leetcode-cn.com/problems/remove-duplicate-letters/solution/c-0ms-ji-bai-100jian-ming-dai-ma-chao-xiang-xi-jie/

class Solution {  // ջ
public:
    string removeDuplicateLetters(string s) {
        string res;

        for (int i = 0; i < s.length(); i++) {
            if (res.find(s[i]) != s.npos)  // �Ѵ��ڴ�������λ�ô�ʱ�ǶԵ�
                continue;

            while (!res.empty() && res.back() > s[i] && s.find(res.back(), i) != s.npos)
                res.pop_back();

            res.push_back(s[i]);
        }

        return res;
    }
};