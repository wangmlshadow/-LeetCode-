#include "normal.h"

/*
���� DNA ����һϵ����дΪ A��C��G �� T �ĺ�������ɣ����磺��ACGAATTCCG�������о� DNA ʱ��ʶ�� DNA �е��ظ�������ʱ����о��ǳ��а�����

��дһ������������ DNA ���������г��ֳ���һ�ε� 10 ����ĸ�������У��Ӵ�����

����ظ����ֵĳ���Ϊ10�������� 

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/repeated-dna-sequences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> helper;
        set<string> have;
        vector<string> res;
        int len = s.length();
        for (int i = 0; i < len - 9; i++) {
            string curSub = s.substr(i, 10);

            if (helper.find(curSub) != helper.end())
                have.insert(curSub);
            else
                helper.insert(curSub);
        }

        for (set<string>::iterator iter = have.begin(); iter != have.end(); iter++)
            res.push_back(*iter);

        return res;
    }
};