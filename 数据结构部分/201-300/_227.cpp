#include "normal.h"

/*
ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ��

�ַ������ʽ�������Ǹ�������+�� - ��*��/ ����������Ϳո�  �� ���������������������֡�
*/

class Solution {
public:
    int calculate(string s) {
        vector<string> rpn;
        toRPN(s, rpn);
        return getRes(rpn);
    }

    void toRPN(string& s, vector<string>& rpn) {   // û������
        int len = s.length();
        stack<string> op;

        for (int i = 0; i < len; i++) {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '+') {
                if (op.empty())
                    op.push("+");
                else {
                    while (!op.empty()) {
                        rpn.push_back(op.top());
                        op.pop();
                    }

                    op.push("+");
                }
            }
            else if (s[i] == '-') {
                if (op.empty())
                    op.push("-");
                else {
                    while (!op.empty()) {
                        rpn.push_back(op.top());
                        op.pop();
                    }

                    op.push("-");
                }
            }
            else if (s[i] == '*') {
                if (op.empty())
                    op.push("*");
                else {
                    if (op.top() == "+" || op.top() == "-")
                        op.push("*");
                    else {
                        rpn.push_back(op.top());
                        op.pop();
                        op.push("*");
                    }
                }
            }
            else if (s[i] == '/') {
                if (op.empty())
                    op.push("/");
                else {
                    if (op.top() == "+" || op.top() == "-")
                        op.push("/");
                    else {
                        rpn.push_back(op.top());
                        op.pop();
                        op.push("/");
                    }
                }
            }
            else {  // ����
                string num;
                num.push_back(s[i]);

                while (i + 1 < len && isdigit(s[i + 1])) {
                    num.push_back(s[i + 1]);
                    i++;
                }

                rpn.push_back(num);
            }
        }

        while (!op.empty()) {
            rpn.push_back(op.top());
            op.pop();
        }
    } 

    int getRes(vector<string>& rpn) {
        int size = rpn.size();
        stack<int> res;

        for (int i = 0; i < size; i++) {
            if (rpn[i] == "+") {
                int x = res.top();
                res.pop();
                int y = res.top();
                res.pop();
                res.push(y + x);
            }
            else if (rpn[i] == "-") {
                int x = res.top();
                res.pop();
                int y = res.top();
                res.pop();
                res.push(y - x);
            }
            else if (rpn[i] == "*") {
                int x = res.top();
                res.pop();
                int y = res.top();
                res.pop();
                res.push(y * x);
            }
            else if (rpn[i] == "/") {
                int x = res.top();
                res.pop();
                int y = res.top();
                res.pop();
                res.push(y / x);
            }
            else {
                res.push(stoi(rpn[i]));
            }
        }

        return res.top();
    }
};