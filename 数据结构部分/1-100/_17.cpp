#include "normal.h"

/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {       
        vector<string> result;
        vector<string> temp_1;
        vector<string> temp_2;

        if (digits.empty())
            return result;

        for (int i = 0; i < digits.size(); i++) {
            switch (digits[i]) {
            case '2':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "a");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "b");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "c");
                result.insert(result.end(), temp_1.begin(), temp_1.end()); 
                break;
            case '3':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "d");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "e");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "f");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            case '4':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "g");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "h");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "i");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            case '5':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "j");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "k");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "l");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            case '6':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "m");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "n");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "o");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            case '7':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "p");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "q");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "r");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "s");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            case '8':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "t");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "u");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "v");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            case '9':
                temp_1 = result;
                temp_2 = result;
                addChar(temp_1, "w");
                result = temp_1;
                temp_1 = temp_2;
                addChar(temp_1, "x");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "y");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                temp_1 = temp_2;
                addChar(temp_1, "z");
                result.insert(result.end(), temp_1.begin(), temp_1.end());
                break;
            default:
                break;
            }
        }
        return result;
    }

    void addChar(vector<string>& str, string ch) {
        if (str.empty()) {
            str.push_back(ch);
            return;
        }
            
        for (int i = 0; i < str.size(); i++) {
            str[i] += ch;
        }
    }
};