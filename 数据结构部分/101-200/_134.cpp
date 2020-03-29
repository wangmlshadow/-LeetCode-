#include "normal.h"

/*

��һ����·���� N ������վ�����е� i ������վ������ gas[i] ����

����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� cost[i] ����������е�һ������վ��������ʼʱ����Ϊ�ա�

���������ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� -1��

˵��:

�����Ŀ�н⣬�ô𰸼�ΪΨһ�𰸡�
���������Ϊ�ǿ����飬�ҳ�����ͬ��
���������е�Ԫ�ؾ�Ϊ�Ǹ�����
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cnt = gas.size();
        int have = 0;

        for (int i = 0; i < cnt; i++) {
            if (gas[i] < cost[i])
                continue;

            have = gas[i];
            int need = i, next = (i + 1) % cnt;

            while (have >= cost[need]) {
                have = have - cost[need] + gas[next];
                need = next;
                next = (next + 1) % cnt;

                if (need == i)
                    return i;
            }           
        }

        return -1;
    }
};