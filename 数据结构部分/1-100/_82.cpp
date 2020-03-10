#include "normal.h"

/*
����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {        
        if (head == NULL)
            return NULL;

        ListNode* last = head;
        ListNode* cur = head;
        int val;
        bool sign = false;   // ͷ�ڵ���Ա�ȷ��

        while (cur != NULL) {
            val = cur->val;
            int cnt = 1;

            while (cur->next != NULL && cur->next->val == val) {
                cur = cur->next;
                cnt++;
            }

            if (cnt == 1) {
                if (sign) {
                    last->next = cur;
                    last = cur;
                }
                else {
                    head = cur;
                    last = cur;
                }

                sign = true;
            }
            else {
                if (sign) {
                    last->next = cur->next;
                }
                else {
                    head = cur->next;
                    last = cur->next;
                }
            }
            
            cur = cur->next;
        }
               
        return head;
    }
};