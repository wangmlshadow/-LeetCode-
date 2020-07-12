#include "normal.h"

/*
������Ϸ ����

���һ���㷨���ж�����Ƿ�Ӯ�˾�����Ϸ��������һ�� N x N ���������̣����ַ�" "��"X"��"O"��ɣ������ַ�" "����һ����λ��

�����Ǿ�����Ϸ�Ĺ���

����������ַ������λ��" "���С�
��һ��������Ƿ��ַ�"O"���ҵڶ���������Ƿ��ַ�"X"��
"X"��"O"ֻ��������ڿ�λ�У���������ѷ����ַ���λ�ý�����䡣
����N����ͬ���ҷǿգ����ַ�����κ��С��л�Խ���ʱ����Ϸ��������Ӧ���ַ�����һ�ʤ��
������λ�÷ǿ�ʱ��Ҳ��Ϊ��Ϸ������
�����Ϸ��������Ҳ������ٷ����ַ���
�����Ϸ���ڻ�ʤ�ߣ��ͷ��ظ���Ϸ�Ļ�ʤ��ʹ�õ��ַ���"X"��"O"���������Ϸ��ƽ�ֽ������򷵻� "Draw"������Ի����ж�����Ϸδ���������򷵻� "Pending"��

1 <= board.length == board[i].length <= 100
����һ����ѭ���������

˼·��
���� ���Խ��� ���Խ��� ÿһ�� ÿһ�� 
*/

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();
        int i = 0;
        string res;

        for (; i < n; i++) {  // �������Խ���Ԫ��
            if (board[i][i] == ' ')
                break;

            if (i != 0 && board[i][i] != board[i - 1][i - 1])
                break;
        }

        if (i == n) {
            res.push_back(board[0][0]);
            return res;
        }
        else
            i = 0;

        for (; i < n; i++) {  // �������Խ���Ԫ��
            if (board[i][n - 1 - i] == ' ')
                break;

            if (i != 0 && board[i][n - 1 - i] != board[i - 1][n - i])
                break;
        }

        if (i == n) {
            res.push_back(board[0][n - 1]);
            return res;
        }
        else
            i = 0;

        // ��j�� ��j��
        for (int j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                if (board[j][i] == ' ')
                    break;

                if (i != 0 && board[j][i] != board[j][i - 1])
                    break;
            }

            if (i == n) {
                res.push_back(board[j][0]);
                return res;
            }

            for (i = 0; i < n; i++) {
                if (board[i][j] == ' ')
                    break;

                if (i != 0 && board[i][j] != board[i - 1][j])
                    break;
            }

            if (i == n) {
                res.push_back(board[0][j]);
                return res;
            }
        }

        for (int j = 0; j < n; j++) {   // ���пո� ��Ϸδ����
            for (int k = 0; k < n; k++) {
                if (board[j][k] == ' ')
                    return "Pending";
            }
        }
    
        return "Draw";  // ƽ��
    }
};

/*
ִ�н����
ͨ��
��ʾ����
ִ����ʱ��4 ms, ������ C++ �ύ�л�����97.65%���û�
�ڴ����ģ�8.2 MB, ������ C++ �ύ�л�����100.00%���û�
*/