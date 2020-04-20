#include "normal.h"

/*
ʹ��ջʵ�ֶ��е����в�����

push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-queue-using-stacks
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        pVal = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (s.empty())
            pVal = x;

        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = 0;
        if (!s.empty()) {
            stack<int> temp;
            while (!s.empty()) {
                temp.push(s.top());
                s.pop();
            }

            res = temp.top();
            temp.pop();

            if (!temp.empty()) {
                pVal = temp.top();

                while (!temp.empty()) {
                    s.push(temp.top());
                    temp.pop();
                }
            }
            else {
                pVal = 0;
            }
        }

        return res;
    }

    /** Get the front element. */
    int peek() {
        return pVal;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }

private:
    int pVal;
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */