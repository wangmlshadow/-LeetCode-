#include "normal.h"

/*
n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
*/

class Solution {    // ���ݷ������ٷ����
private:
    vector<vector<string>> result;   // �����
    // �ֱ��׼��Щ�С����Խ��ߡ����Խ��߻ᱻ����
    vector<int> rows;
    vector<int> leadingDiag;
    vector<int> countreDiag;
    // �ʺ󱻷��õ�λ��
    vector<int> queen;
    int n;

    void backtrack(int row) {
        if (row >= n)
            return;

        // ��row�еĸ��г��Է���
        for (int col = 0; col < n; col++) {
            if (isNotUnderAttack(row, col)) {
                placeQueen(row, col);

                if (row == n - 1)   // ���������һ������
                    addSolution();
                else
                    backtrack(row + 1);

                removeQueen(row, col);   // ������һ��
            }
        }
    }

    bool isNotUnderAttack(int row, int col) {
        int res = rows[col] + leadingDiag[row - col + n - 1] + countreDiag[row + col];

        return res == 0;
    }

    void placeQueen(int row, int col) {
        queen[row] = col;
        rows[col] = 1;
        leadingDiag[row - col + n - 1] = 1;
        countreDiag[row + col] = 1;
    }

    void removeQueen(int row, int col) {
        queen[row] = 0;
        rows[col] = 0;
        leadingDiag[row - col + n - 1] = 0;
        countreDiag[row + col] = 0;
    }

    void addSolution() {
        vector<string> solution;

        for (int i = 0; i < n; i++) {
            int col = queen[i];
            string temp;

            for (int j = 0; j < col; j++) {
                temp.push_back('.');
            }

            temp.push_back('Q');

            for (int j = 0; j < n - 1 - col; j++) {
                temp.push_back('.');
            }

            solution.push_back(temp);
        }

        result.push_back(solution);
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        rows = vector<int>(n, 0);
        leadingDiag = vector<int>(2 * n - 1, 0);
        countreDiag = vector<int>(2 * n - 1, 0);
        queen = vector<int>(n, 0);
        this->n = n;
        backtrack(0);

        return result;
    }
};