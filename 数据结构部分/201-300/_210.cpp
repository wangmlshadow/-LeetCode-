#include "normal.h"

/*

�������ܹ��� n �ſ���Ҫѡ����Ϊ 0 �� n-1��

��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡� ���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ����: [0,1]

�����γ������Լ����ǵ��Ⱦ�������������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳��

���ܻ��ж����ȷ��˳����ֻҪ����һ�־Ϳ����ˡ����������������пγ̣�����һ�������顣
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int size = prerequisites.size();
        vector<int> res;

        for (int i = 0; i < size; i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int point = q.front();
            q.pop();
            res.push_back(point);
            int numOut = graph[point].size();

            for (int i = 0; i < numOut; i++) {
                indegree[graph[point][i]]--;

                if (indegree[graph[point][i]] == 0)
                    q.push(graph[point][i]);
            }
        }

        if (res.size() == numCourses)
            return res;
        
        return {};
    }
};