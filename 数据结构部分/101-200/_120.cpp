#include "normal.h"

/*
����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {   // ������������ǵ��γ� ��triangleĳ��ĳԪ�ؼ�������һ����������Ԫ���е���Сֵ
        int size = triangle.size();

        if (size == 0)
            return 0;

        for (int i = 1; i < size; i++) {
            int size_2 = triangle[i].size() - 1;

            for (int j = 0; j <= size_2; j++) {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][0];
                else if (j == size_2)
                    triangle[i][j] += triangle[i - 1][i - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);                   
            }
        }
        
        int min = triangle[size - 1][0];

        for (int i = 1; i < triangle[size - 1].size(); i++) {
            if (min > triangle[size - 1][i])
                min = triangle[size - 1][i];
        }

        return min;
    }
};