#include "normal.h"

/*
����һ�����ص��� ������������ʼ�˵�����������б�

���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool sign = false;   // ���newInterval�Ƿ��Ѿ��������

        for (int i = 0; i < intervals.size(); i++) {
            if (sign)
                result.push_back(intervals[i]);
            else {
                if (intervals[i][0] > newInterval[1]) {
                    result.push_back(newInterval);
                    sign = true;
                    result.push_back(intervals[i]);
                }
                else if (intervals[i][1] < newInterval[0]) {
                    result.push_back(intervals[i]);
                }
                else {
                    newInterval[0] = min(intervals[i][0], newInterval[0]);
                    newInterval[1] = max(intervals[i][1], newInterval[1]);
                }
            }           
        }

        if (!sign)
            result.push_back(newInterval);

        return result;
    }
};