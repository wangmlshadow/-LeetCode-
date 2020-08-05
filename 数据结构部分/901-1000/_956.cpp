#include "normal.h"

/*
��̬�滮

�����ڰ�װһ������ƣ���ϣ�����߶����������ƽ�����������֧�ܣ����߸�һ����ÿ����֧�ܵĸ߶ȱ�����ȡ�

����һ�ѿ��Ժ�����һ��ĸֽ� rods���ٸ����ӣ�����ֽ�ĳ���Ϊ 1��2 �� 3������Խ����Ǻ�����һ���γɳ���Ϊ 6 ��֧�ܡ�

���ع���Ƶ������ܰ�װ�߶ȡ����û����װ����ƣ��뷵�� 0��

0 <= rods.length <= 20
1 <= rods[i] <= 1000
�ֽ�ĳ����ܺ����Ϊ 5000

*/

class Solution { 
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> minDrop(sum + 1, INT_MAX);
        vector<bool> canget(sum + 1, false);
        minDrop[0] = 0;
        canget[0] = true;

        for (auto i : rods) {
            for (int j = sum; j >= 0; j--) {
                if (j - i >= 0 && canget[j - i]) {
                    canget[j] = true;
                    minDrop[j] = min(minDrop[j], minDrop[j - i] + i);
                }

                if (j - 2 * i >= 0 && canget[j - 2 * i]) {
                    canget[j] = true;
                    minDrop[j] = min(minDrop[j], minDrop[j - 2 * i]);
                }
            }
        }

        return (sum - minDrop[sum]) / 2;
    }
};