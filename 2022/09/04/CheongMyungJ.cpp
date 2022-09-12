//Runtime: 27 ms, faster than 97.93% of C++ online submissions for Rotate Array.
//Memory Usage: 25.1 MB, less than 57.05% of C++ online submissions for Rotate
//O(k)로 품
//특정위치에서 k다음자리에 값 넣어주고 그걸 k다음자리에 넣어주고~~~반복.
//순환이 생기면 바로 다음위치부터 다시 시작.
//바로 다음위치가 이미 순환했던 위치가 아닌 이유는 
//만약 순환했던 위치라면 순환을 돌면서 바로 다음위치도 갔다는 소리고, 
//그 말은 계속 한칸씩 밀려서 전부 다 볼 수 있다는 의미기 때문에 
//바로 다음 위치는 절대 순환에 포함될 수 없음.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        int first_index = 0;
        for (int i = 0; i < nums.size(); i++){
            first_index = i;
            int index = i;
            int next_index;
            int num = nums[index];
            int next_num;
            do{
                next_index = (index + k)%nums.size();
                next_num = nums[next_index];
                nums[next_index] = num;
                num = next_num;
                index = next_index;
                count++;
            }
            while(first_index != next_index);
            if (count == nums.size())
                break;
        }
    }
};
