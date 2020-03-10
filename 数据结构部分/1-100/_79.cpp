#include "normal.h"

/*
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-search
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


class Solution {    // ͨ���ˣ�����ͦ���ģ�backtrack()���ԸĽ����ȵڶ��鿴��Ŀ�ٸ�
public:
    bool exist(vector<vector<char>>& board, string word) {
        sign = false;
        m = board.size();
        len = word.length();

        if (m == 0)
            return len == 0;

        n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        backtrack(0, 0, used, 0, word, board);

        return sign;
    }

private:
    bool sign;
    int m;
    int n;
    int len;

    void backtrack(int row, int col, vector<vector<bool>> used, int pos, string& word, vector<vector<char>>& board) {
        if (sign)
            return;

        if (pos == 0) {
            for (int i = row; i < m; i++) {
                for (int j = col; j < n; j++) {
                    if (word[pos] == board[i][j]) {
                        if (pos == word.length() - 1) {
                            sign = true;
                            return;
                        }

                        vector<vector<bool>> temp = used;
                        temp[i][j] = true;
                        backtrack(i, j, temp, pos + 1, word, board);
                    }
                }
            }
        }
        else {
            // ��������
            if (row > 0 && used[row - 1][col] == false && word[pos] == board[row - 1][col]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row - 1][col] = true;
                backtrack(row - 1, col, temp, pos + 1, word, board);
            }

            if (row < m - 1 && used[row + 1][col] == false && word[pos] == board[row + 1][col]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row + 1][col] = true;
                backtrack(row + 1, col, temp, pos + 1, word, board);
            }

            if (col > 0 && used[row][col - 1] == false && word[pos] == board[row][col - 1]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row][col - 1] = true;
                backtrack(row, col - 1, temp, pos + 1, word, board);
            }

            if (col < n - 1 && used[row][col + 1] == false && word[pos] == board[row][col + 1]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row][col + 1] = true;
                backtrack(row, col + 1, temp, pos + 1, word, board);
            }
        }
    }
};