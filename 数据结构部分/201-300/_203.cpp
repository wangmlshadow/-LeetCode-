#include "normal.h"

/*
ɾ�������е��ڸ���ֵ val �����нڵ㡣
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;

        while (cur != NULL && cur->val == val)
            cur = cur->next;

        if (cur == NULL)
            return cur;

        head = cur;
        ListNode* pre = head;
        cur = cur->next;

        while (cur != NULL) {
            if (cur->val != val)
                pre = cur;
            else
                pre->next = cur->next;

            cur = cur->next;
        }

        return head;
    }
};