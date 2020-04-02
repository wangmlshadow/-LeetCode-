#include "normal.h"

/*
��������в�������
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {   // ��ʱ��??  
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* cur = head->next;
        ListNode* ahead = head;

        while (cur != NULL) {
            ListNode* pos_1 = NULL;
            ListNode* pos_2 = head;

            while (pos_2 != cur) {   // ��ʱԭ��Ӧ���Ƕ�ÿһ��cur����ͷ��ʼ�Ƚ�һ�飬����ڴ�ƪ����д�ĵ������������һ���ж�cur�Ƿ���Ҫ��������
                if (pos_2->val > cur->val)
                    break;

                pos_1 = pos_2;
                pos_2 = pos_2->next;
            }

            if (pos_2 == cur) {
                ahead = cur;
                cur = cur->next;
            }
            else {
                if (pos_1 == NULL) {
                    ahead->next = cur->next;
                    cur->next = head;
                    head = cur;
                    cur = head->next;
                }
                else {
                    ahead->next = cur->next;
                    pos_1->next = cur;
                    cur->next = pos_2;
                    cur = ahead->next;
                }
            }
        }

        return head;
    }
};


class Solution {  // ʹ��map��key��������� �����ⲻ�ǲ������� ����ͨ����.....
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        map<int, vector<ListNode*>> helper;   // ʹ��vector<ListNode*> �����ظ�
        ListNode* cur = head;

        while (cur != NULL) {
            map<int, vector<ListNode*>>::iterator iter = helper.find(cur->val);

            if (iter == helper.end()) {
                helper[cur->val] = { cur };
            }
            else {
                helper[cur->val].push_back(cur);
            }

            cur = cur->next;
        }

        map<int, vector<ListNode*>>::iterator iter = helper.begin();
        cur = NULL;

        while (iter != helper.end()) {
            int size = iter->second.size();

            if (iter == helper.begin()) {
                head = iter->second[0];
                cur = head;

                for (int i = 1; i < size; i++) {
                    cur->next = iter->second[i];
                    cur = cur->next;
                }
            }
            else {
                for (int i = 0; i < size; i++) {
                    cur->next = iter->second[i];
                    cur = cur->next;
                }
            }

            iter++;
        }

        cur->next = NULL;

        return head;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
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