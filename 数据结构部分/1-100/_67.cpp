#include "normal.h"

/*

���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int plus = 0;
        int len_1 = a.length();
        int len_2 = b.length();
        int pos = 0;
        string result;

        while (plus == 1 || pos < len_1 || pos < len_2) {
            if (pos < len_1 && pos < len_2) {
                if (a[len_1 - 1 - pos] == '1') {
                    if (b[len_2 -1 -pos] == '1') {
                        if (plus == 1) {
                            result.push_back('1');
                        }
                        else {
                            plus = 1;
                            result.push_back('0');
                        }
                    }
                    else {
                        if (plus == 1) {
                            result.push_back('0');
                        }
                        else {
                            result.push_back('1');
                        }
                    }
                }
                else {
                    if (b[len_2 - 1 - pos] == '1') {
                        if (plus == 1) {
                            result.push_back('0');
                        }
                        else {
                            result.push_back('1');
                        }
                    }
                    else {
                        if (plus == 1) {
                            result.push_back('1');
                            plus = 0;
                        }
                        else {
                            result.push_back('0');
                        }
                    }
                }
            }
            else if (pos < len_1 && pos >= len_2) {
                if (a[len_1 - 1 - pos] == '1') {
                    if (plus == 1) {
                        result.push_back('0');
                    }
                    else {
                        result.push_back('1');
                    }
                }
                else {
                    if (plus == 1) {
                        result.push_back('1');
                        plus = 0;
                    }
                    else {
                        result.push_back('0');
                    }
                }
            }
            else if (pos >= len_1 && pos < len_2) {
                if (b[len_2 - 1 - pos] == '1') {
                    if (plus == 1) {
                        result.push_back('0');
                    }
                    else {
                        result.push_back('1');
                    }
                }
                else {
                    if (plus == 1) {
                        result.push_back('1');
                        plus = 0;
                    }
                    else {
                        result.push_back('0');
                    }
                }
            }
            else {
                result.push_back('1');
                plus = 0;
            }

            pos++;
        }

        int len = result.length();

        for (int i = 0; i < len / 2; i++) {
            char ch = result[i];
            result[i] = result[len - 1 - i];
            result[len - 1 - i] = ch;
        }

        return result;
    }
};