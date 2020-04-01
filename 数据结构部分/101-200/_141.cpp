#include "normal.h"

/*
����һ�������ж��������Ƿ��л���

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/linked-list-cycle
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL)
            return false;

        ListNode* oneStep = head;
        ListNode* twoStep = head;

        while (twoStep != NULL) {
            oneStep = oneStep->next;
            if (twoStep->next != NULL)
                twoStep = twoStep->next->next;
            else
                return false;

            if (oneStep == twoStep)
                return true;
        }

        return false;
    }
};