#include "normal.h"

/*
����һ���������������������ڵĽڵ㣬�����ؽ����������

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return head;

        ListNode* cur = head;
        ListNode* temp_1 = head->next;
        ListNode* temp_2 = head->next->next;

        cur->next = temp_2;
        temp_1->next = cur;
        head = temp_1;

        ListNode* ahead = cur;
        cur = temp_2;

        while (cur != NULL) {
            if (cur->next == NULL)
                break;

            temp_1 = cur->next;
            temp_2 = cur->next->next;

            ahead->next = temp_1;
            cur->next = temp_2;
            temp_1->next = cur;
            ahead = cur;
            cur = temp_2;
        }

        return head;
    }
};