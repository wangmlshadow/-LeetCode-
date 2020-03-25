#include "normal.h"

/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;

            while (right > left && !isalnum(s[right]))
                right--;

            if (left < right) {
                if (s[left] == s[right]) {
                    left++;
                    right--;
                    continue;
                }

                if (isdigit(s[left])) {
                    if (s[left] == s[right]) {
                        left++;
                        right--;
                        continue;
                    }
                    else
                        return false;
                }
                else {
                    if ((char)(toupper(s[left])) == (char)(toupper(s[right]))) {
                        left++;
                        right--;
                        continue;
                    }
                    else
                        return false;
                }
            }
        }

        return true;
    }
};