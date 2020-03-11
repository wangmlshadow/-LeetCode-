#include "normal.h"

/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*/

class Solution {    // �Ƚ���
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        int size = heights.size();

        for (int i = 0; i < size; i++) {
            int min = heights[i];

            for (int j = i; j < size; j++) {
                if (min > heights[j])
                    min = heights[j];

                if (max < (j - i + 1) * min)
                    max = (j - i + 1) * min;
            }
        }

        return max;
    }
};



class Solution {    // ���η���ʱ�ˣ���������û��ʱ��������������ΪN��1��
public:
    int largestRectangleArea(vector<int>& heights) {
        return solution(0, heights.size() - 1, heights);
    }

    int solution(int start, int end, vector<int>& heights) {
        if (start > end)
            return 0;

        if (start == end)
            return heights[start];

        int min = start;

        for (int i = start + 1; i <= end; i++) {
            if (heights[min] > heights[i])
                min = i;
        }

        return max((end - start + 1) * heights[min], max(solution(start, min - 1, heights), solution(min + 1, end, heights)));
    }
};


class Solution {    // ���η��Ż����Ż���ʽ��������п�����һ��Ҳ����������Ļش�
public:
    int largestRectangleArea(vector<int>& heights) {
        return solution(0, heights.size() - 1, heights);
    }

    int solution(int start, int end, vector<int>& heights) {
        if (start > end)
            return 0;

        if (start == end)
            return heights[start];

        int min = start;

        for (int i = start + 1; i <= end; i++) {
            if (heights[min] > heights[i])
                min = i;
        }

        int left = min - 1;
        int right = min + 1;

        while (left >= start && heights[left] == heights[min])
            left--;

        while (right <= end && heights[right] == heights[min])
            right++;

        return max((end - start + 1) * heights[min], max(solution(start, left, heights), solution(right, end, heights)));
    }
};   // ���η����ǲ��찡




