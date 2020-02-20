#include "normal.h"

/*
����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������

k ��һ��������������ֵС�ڻ��������ĳ��ȡ�

����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

ʾ�� :

�����������1->2->3->4->5

�� k = 2 ʱ��Ӧ������: 2->1->4->3->5

�� k = 3 ʱ��Ӧ������: 3->2->1->4->5

˵�� :

����㷨ֻ��ʹ�ó����Ķ���ռ䡣
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻��
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;

        ListNode* ahead;
        ListNode* next;
        ListNode* cur = head;
        ListNode* temp_1;
        ListNode* ahead_k;

        int cnt = 1;

        while (cur->next != NULL && cnt < k) {
            cur = cur->next;
            cnt++;
        }

        if (cnt != k) {
            return head;
        }
        else {
            ahead = head;
            head = cur;
            next = cur->next;
            ahead_k = ahead;
                       
            for (int i = 0; i < k; i++) {
                temp_1 = ahead->next;
                ahead->next = next;
                next = ahead;
                ahead = temp_1;
            }
        }

        while (ahead_k->next != NULL) {
            cnt = 1;
            cur = ahead_k->next;

            while (cur->next != NULL && cnt < k) {
                cur = cur->next;
                cnt++;
            }

            if (cnt != k) {
                return head;
            }
            else {
                ahead = ahead_k->next;
                ahead_k->next = cur;
                next = cur->next;
                ahead_k = ahead;

                for (int i = 0; i < k; i++) {
                    temp_1 = ahead->next;
                    ahead->next = next;
                    next = ahead;
                    ahead = temp_1;
                }
            }
        }

        return head;
    }
};