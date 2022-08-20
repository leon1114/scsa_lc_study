//Runtime: 67 ms, faster than 99.76% of C++ online submissions for Gas Station.
//Memory Usage: 69.5 MB, less than 52.67% of C++ online submissions for Gas Station.
//한바퀴 돌건데 각 index마다 시작점이라고 가정하고 돌거임(for i)
//시작점에서부터 쭉 가보는데 불가능한 시점이 되면 그 다음 시점을 시작점이라고 다시 가정하고 반복(for j, i = temp_j)
//만약 그 다음 시점이 다시 한바퀴 돌아서 0번 index 이후라면 어짜피 불가능하니까 return -1;
//한바퀴 도는동안 문제없었으면 해당 if(flag == true) return i;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        
        for (int i = 0; i < size; i++){
            int temp = 0;
            bool flag = true;
            for (int j = i; j < i + size; j++){
                int temp_j = j % size;
                temp += gas[temp_j] - cost[temp_j];
                if (temp < 0) {
                    if (temp_j < j)
                        return -1;
                    i = temp_j;
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                return i;
        }
        return -1;
    }
};
