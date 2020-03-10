#include "normal.h"

/*

����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode* cur = head->next;
        ListNode* last = head;

        while (cur != NULL) {
            if (last->val == cur->val) {
                last->next = cur->next;
                cur = cur->next;
            }
            else {
                last = cur;
                cur = cur->next;
            }                                      
        }

        return head;
    }
};