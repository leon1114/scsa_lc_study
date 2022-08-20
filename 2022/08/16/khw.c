/*
Runtime: 117 ms, faster than 68.82% of C online submissions for Gas Station.
Memory Usage: 11.6 MB, less than 48.39% of C online submissions for Gas Station.

가스 - 코스트 한 값들을 누적으로 더해가는 배열을 하나 만들어서의
최소값의 다음 Index를 return 함.
누적합의 마지막 값이 0보다 작으면 완주 못하기 때문에 -1 리턴
*/

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    //sum[] : i까지 누적 합
    //누적합의 마지막 칸이 - 이면 완주 못함

    int sum[gasSize];
    sum[0] = gas[0] - cost[0];
    int min = sum[0];
    int minIdx = 0;    
    
    for (int i = 1; i < gasSize; i++)
    {
        sum[i] = gas[i] - cost[i] + sum[i-1];
        if(sum[i] < min){
            min = sum[i];
            minIdx = i;
        }
    }
    if(sum[gasSize-1] < 0) return -1;
    else return (minIdx+1)%gasSize;
}
