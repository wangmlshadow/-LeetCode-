#include "normal.h"

/*
���ж�һ�������Ƿ�Ϊ��������
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ch = head;
        return check(head);
    }

private:
    ListNode* ch;

    bool check(ListNode* cur) {
        if (cur != NULL) {
            if (!check(cur->next))
                return false;

            if (cur->val != ch->val)
                return false;

            ch = ch->next;
        }

        return true;
    }
};