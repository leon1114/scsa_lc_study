//Runtime: 3 ms, faster than 62.06% of C++ online submissions for Reverse Integer.
//Memory Usage: 6 MB, less than 32.42% of C++ online submissions for Reverse Integer.

// 코너케이스(인트범위 넘어가는경우, 음수)처리를 위해 long long int에 담고 부호는 양수로 바꾸고 시작. 
class Solution {
public:
    int reverse(int x) {
        long long int origin = x;
        bool isplus = true;
        if (origin < 0){
            isplus = false;
            origin *= -1;
        }
        long long int ret = 0;
        for (int i = 0; i < 10; i++){
            ret += origin % 10;
            origin /= 10;
            if (origin == 0) 
                break;
            ret *= 10;
        }
        if (ret > 0x7fffffff || ret < (int)0xffffffff){
            return 0;
        }
        return isplus ? (int)ret : (int)(ret * -1);
    }
};
