#include "normal.h"

/*
ʹ�ö���ʵ��ջ�����в�����

push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��
ע��:

��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek/pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        topV = 0;
        cnt = 0;
    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        topV = x;
        cnt++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int i = 1;
        if (!q.empty()) {
            queue<int> temp;
            

            while (i < cnt) {
                temp.push(q.front());

                if (i == cnt - 1) {
                    topV = q.front();
                    q.pop();
                    i = q.front();
                    break;
                }
                    
                q.pop();
                i++;               
            }

            q = temp;
            cnt--;
        }

        return i;
    }

    /** Get the top element. */
    int top() {
        return topV;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return cnt == 0;
    }

private:
    queue<int> q;
    int topV;
    int cnt;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ :0 ms, ������ C++ �ύ�л�����100.00%���û�
�ڴ����� :7.1 MB, ������ C++ �ύ�л�����100.00%���û�
*/