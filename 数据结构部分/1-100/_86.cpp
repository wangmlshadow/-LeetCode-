#include "normal.h"

/*
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = head;
        ListNode* right;
        ListNode* cur = head;

        while (cur != NULL) {
            if (cur->val >= x)
                break;
            left = cur;
            cur = cur->next;
        }

        if (cur == NULL)
            return head;

        ListNode* ahead = cur;
        right = cur->next;

        while (right != NULL) {
            if (right->val >= x) {
                ahead = right;
                right = right->next;
            }
            else {
                ahead->next = right->next;

                if (head == cur) {
                    right->next = head;
                    head = right;
                    left = head;
                }
                else {
                    right->next = left->next;
                    left->next = right;
                    left = right;
                }

                right = ahead->next;
            }
        }        
       
        return head;
    }
};