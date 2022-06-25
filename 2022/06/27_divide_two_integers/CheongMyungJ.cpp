//Runtime: 4 ms, faster than 48.06% of C++ online submissions for Divide Two Integers.
//Memory Usage: 5.9 MB, less than 28.55% of C++ online submissions for Divide Two Integers.
//비트연산중 시프트 연산으로 곱하기 대체해서 품...
//divisor를 시프트해서 dividend보다 작으면서 가장 큰 값으로 만든다음 빼줌
//그리고 divisor를 오른쪽으로 시프트 한번
//dividend보다 divisor가 작으면 빼고 아니면 빼지 않고 divisor 오른쪽 시프트 한번
//작업 반복하면서 dividend < divisor이면 나감
//위 작업하면서 2^x 값을 ret에 계속 더함
//마지막으로 범위 체크해서 결과 리턴

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_negative = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            is_negative = true;

        long long int lld_dividend = dividend < 0 ? -(long long int)dividend : dividend;
        long long int lld_divisor = divisor < 0 ? -(long long int)divisor : divisor;

        if (lld_dividend < lld_divisor)
            return 0;

        long long int ret = 0;
        int shift_count = 0;

        while (lld_dividend >= lld_divisor) {
            lld_divisor = (lld_divisor << 1);
            shift_count++;
        }
        lld_divisor = (lld_divisor >> 1);
        shift_count--;

        while (shift_count >= 0) {
            if (lld_dividend >= lld_divisor) {
                lld_dividend -= lld_divisor;
                ret += (1ll << shift_count);
            }
            lld_divisor = (lld_divisor >> 1);
            shift_count--;
        }
        if (is_negative == true)
            return -ret < INT32_MIN? INT32_MIN : -ret;
        return ret > INT32_MAX? INT32_MAX : ret;
    }
};
