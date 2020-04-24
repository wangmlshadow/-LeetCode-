#include "normal.h"

/*
����һ������������ 0-9 ���ַ�����һ��Ŀ��ֵ��������֮����Ӷ�
Ԫ�����������һԪ��+��- �� * �����������ܹ��õ�Ŀ��ֵ�ı��ʽ��
*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        string track = "";
        size = num.size();
        backtrack(num, target, 0, 0, 1, track);
        return res;
    }

private:
    vector<string> res;
    int size;

    void backtrack(string& num, int& target, int index, long val, long mult, string& track) {   // mult ��һ������ʱ�ұߵĲ�����
        if (index == size) {
            if (val == target)
                res.push_back(track);
            return;
        }
        
        int len = track.size();

        for (int i = index; i < size; i++) {
            string sVal = num.substr(index, i - index + 1);
            long n = stol(sVal);

            if (index == 0) {
                track += sVal;
                backtrack(num, target, i + 1, n, n, track);
                track.resize(len);
            }
            else {
                track += "+" + sVal;
                backtrack(num, target, i + 1, val + n, n, track);
                track.resize(len);

                track += "-" + sVal;
                backtrack(num, target, i + 1, val - n, -n, track);  // -n ͳһ�˼Ӽ�
                track.resize(len);

                track += "*" + sVal;
                backtrack(num, target, i + 1, val - mult + mult * n, mult * n, track);
                track.resize(len);
            }

            if (n == 0)  // ����0֮�� û��01 02 ��0��ͷ����
                return;
        }            
    }
};
