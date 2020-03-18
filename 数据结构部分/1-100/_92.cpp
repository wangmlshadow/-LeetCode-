#include "normal.h"

/*
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��

˵��:
1 �� m �� n �� �����ȡ�
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {   
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;

        if (m == 1) {
            ListNode* cur = head->next;
            ListNode* ahead = head;
            int cnt = 2;

            while (cur != NULL) {
                ListNode* next = cur->next;
                cur->next = ahead;
                ahead = cur;
                
                if (cnt == n) {
                    head->next = next;
                    return cur;
                }

                cur = next;
                cnt++;
            }
        }
        else {
            ListNode* cur = head;
            ListNode* ahead;
            ListNode* left;
            ListNode* right;
            int cnt = 1;

            while (cur != NULL) {              
                if (cnt == m - 1) {
                    left = cur;
                    cur = cur->next;
                }                                 
                else if (cnt == m) {
                    ahead = cur;
                    right = cur;
                    cur = cur->next;
                }                   
                else if (cnt > m && cnt < n) {
                    ListNode* next = cur->next;
                    cur->next = ahead;
                    ahead = cur;
                    cur = next;
                }
                else if (cnt == n) {
                    ListNode* next = cur->next;
                    cur->next = ahead;
                    left->next = cur;
                    right->next = next;
                    return head;
                }
                else {
                    cur = cur->next;
                }
                cnt++;
            }
        }

        return head;
    }
};