#include "normal.h"

/*
�� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* first = new ListNode(INT_MIN);
        first->next = head;
        ListNode* cur = head->next;
        ListNode* pre = head;

        while (cur != NULL) {
            ListNode* nextPos = cur->next;

            if (pre->val <= cur->val) {
                pre = cur;
            }
            else {
                ListNode* temp = first;

                while (temp->next->val < cur->val)
                    temp = temp->next;

                pre->next = nextPos;
                cur->next = temp->next;
                temp->next = cur;               
            }

            cur = nextPos;
        }

        return first->next;
    }
};