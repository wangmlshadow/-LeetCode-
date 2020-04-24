#include "normal.h"

/*

���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��
������⡣����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�

�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��

�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г�
��ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����
*/

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {   // ����
public:
    int firstBadVersion(int n) {
        long left = 1, right = n;

        while (left < right) {
            long mid = (left + right) / 2;
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return min(left, right);
    }
};