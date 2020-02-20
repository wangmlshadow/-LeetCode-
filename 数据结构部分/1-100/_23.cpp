#include "normal.h"

/*
�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {  // �����ڹ鲢����ķ���
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;

        if (lists.size() == 1)
            return lists[0];

        int cnt;
        vector<ListNode*> temp_1(lists);
        vector<ListNode*> temp_2;

        while (temp_1.size() != 1) {
            for (cnt = 0; cnt < temp_1.size(); ) {
                if (cnt == temp_1.size() - 1) {
                    temp_2.push_back(temp_1[cnt]);
                    break;
                }
                
                temp_2.push_back(mergeTwoLists(temp_1[cnt], temp_1[cnt + 1]));
                cnt += 2;
            }
            temp_1 = temp_2;
            temp_2.clear();
        }
        return temp_1[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        if (l1 == NULL)
            return l2;

        if (l2 == NULL)
            return l1;

        ListNode* head;
        ListNode* cur;

        if (l1->val < l2->val) {
            head = l1;
            cur = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            cur = l2;
            l2 = l2->next;
        }


        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        if (l1 != NULL)
            cur->next = l1;

        if (l2 != NULL)
            cur->next = l2;

        return head;
    }
};

/*
ִ����ʱ :16 ms, ������ C++ �ύ�л�����98.52%���û�
�ڴ����� :11.4 MB, ������ C++ �ύ�л�����31.65%���û�
*/


