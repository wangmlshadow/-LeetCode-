#include "normal.h"

/*

�����ѧ�ڱ���ѡ�� numCourse �ſγ̣���Ϊ 0 �� numCourse-1 ��

��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡� ���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ���ǣ�[0,1]

�����γ������Լ����ǵ��Ⱦ������������ж��Ƿ����������пγ̵�ѧϰ��
*/

class Solution {  // �ж�ͼ���Ƿ��л� ��������
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int size = prerequisites.size();

        for (int i = 0; i < size; i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int cnt = 0;

        while (!q.empty()) {
            int point = q.front();
            q.pop();
            cnt++;
            int numOut = graph[point].size();

            for (int i = 0; i < numOut; i++) {
                indegree[graph[point][i]]--;

                if (indegree[graph[point][i]] == 0)
                    q.push(graph[point][i]);
            }
        }

        return cnt == numCourses;
    }
};