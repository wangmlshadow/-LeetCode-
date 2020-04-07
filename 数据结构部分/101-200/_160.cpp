#include "normal.h"

/*
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

�����������û�н��㣬���� null.
�ڷ��ؽ���������������뱣��ԭ�еĽṹ��
�ɼٶ���������ṹ��û��ѭ����
���������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-linked-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // ��set�Ļ��ռ临�Ӷ�ΪO(n)
        //set<ListNode*> setA;

        // ˫ָ�뷨
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != NULL && curB != NULL) {   // ��A Bһ���� ����н����һ������Ϳ����ҳ� �����һ���� ����н��� �ڶ��α��������ҳ� ���û�н���curA curB���ڵڶ��α���ʱ����ͬΪNULL
            if (curA == curB)
                return curA;
            
            curA = curA->next;
            curB = curB->next;

            if (curA == NULL && curB == NULL)
                return NULL;

            if (curA == NULL)
                curA = headB;

            if (curB == NULL)
                curB = headA;
        }

        return NULL;
    }
};