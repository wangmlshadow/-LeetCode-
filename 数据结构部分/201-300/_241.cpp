#include "normal.h"

/*
����һ���������ֺ���������ַ�����Ϊ���ʽ������ţ��ı����������ȼ������
��ͬ�Ľ��������Ҫ�������п��ܵ���ϵĽ������Ч��������Ű��� +, - �Լ� * ��
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.length();

        if (len == 0)
            return vector<int>();

        if (mem.find(input) != mem.end())
            return mem[input];

        vector<int> res;
        int num = 0;
        int index = 0;

        while (index < len && isdigit(input[index]))
            num = num * 10 + input[index++] - '0';

        if (index == len) {
            res.push_back(num);
            mem[input] = res;
            return res;
        }

        for (int i = 0; i < len; i++) {
            if (!isdigit(input[i])) {  // ���������� ��input��Ϊ����������
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));

                for (auto left : res1) {
                    for (auto right : res2) {
                        char op = input[i];
                        res.push_back(caculate(left, op, right));
                    }
                }
            }
        }

        mem[input] = res;
        return res;
    }

private:
    map<string, vector<int>> mem;

    int caculate(int left, char op, int right) {
        switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        }

        return -1;
    }
};