//Runtime: 41 ms, faster than 95.16% of C++ online submissions for Perfect Squares.
//Memory Usage: 5.9 MB, less than 94.31% of C++ online submissions for Perfect Squares.
// DP로 풀었음. n-1 + 1, n-4 + 4, n-9 + 9 .... 이렇게 perfect square 만큼 작은 숫자의 답 보다 하나 큰것들 중 가장 작은것을 선택하는 방식

class Solution {
public:
    int numSquares(int n) {
        int arr[10001]{};
        for (int i = 1; i <= 100; i++){
            arr[i * i] = 1;
        }
        for (int i = 2; i <= n; i++){
            if (arr[i] == 1) continue;
            int temp = 10000;
            for (int j = 1; j <= 100; j++){
                if (i - j * j < 0) break;
                if (temp > arr[i - j * j] + 1){
                    temp = arr[i - j * j] + 1;
                }
            }
            arr[i] = temp;
        }
        return arr[n];
    }
};
