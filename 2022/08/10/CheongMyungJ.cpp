// 예전에 오늘의문제로 풀었던 문제네 개꿀 ㅋㅋㅋ
// 어떻게 했냐면 배열을 돌면서 해시에 넣을건데, key는 숫자, value는 struct st로 할거임
// 해시에 넣을 때 key의 왼오른쪽을 먼저 확인해 봄
// 만약 왼쪽에 이미 해시 key가 존재한다면 그 왼쪽의 lower_index(연결된 가장 작은 숫자)를 가지고 이번 key의 value의 lower_index를 업데이트해줌
// 내가 3을 넣을거고 2가 이미 들어가있다면 key 2인 value의 lower_index (대충 -1로 가정)를 key 3의 value의 lower_index로 넣어주는거지
// 그럼 -1부터 3이 연결됐다고 보는거임
// 오른쪽도 같은 방법으로 하는데, 만약 내 왼쪽 오른쪽 둘다 이미 키가 들어있다면 (3을 넣는데 2, 4가 이미 hash에 등록된 상태)
// 오른쪽에선 upper_index, 왼쪽에선 lower_index를 가지고 오른쪽 lower_index를 왼쪽 lower_index, 왼쪽 upper_index를 오른쪽 upper_index로 바꿔줌
// 즉 왼오른 시작/끝을 이어주는거지
// 이런식으로 배열 한번 돌면서 해시에 넣고 value 업데이트해주면 O(n)으로 풀수있음. (해시에 넣는거, 빼는건 O(1)이기 때문)

class Solution {
public:
    static const int null_index = 0x7fffffff;
    struct st{
        int lower_index;
        int upper_index;
        bool is_checked;
        st(){
            lower_index = null_index;
            upper_index = null_index;
            is_checked = false;
        }
    };
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, st> hash;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++){
            hash[nums[i]] = st();
            hash[nums[i] - 1] = st();
            hash[nums[i] + 1] = st();
        }
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if (hash[num].is_checked == false){
                if (hash[num].lower_index != null_index && hash[num].upper_index != null_index){
                    hash[hash[num].lower_index - 1].upper_index = hash[num].upper_index;
                    hash[hash[num].upper_index + 1].lower_index = hash[num].lower_index;
                    if (ret < hash[num].upper_index - hash[num].lower_index + 1)
                        ret = hash[num].upper_index - hash[num].lower_index + 1;
                }
                else if (hash[num].lower_index != null_index){
                    hash[num + 1].lower_index = hash[num].lower_index;
                    hash[hash[num].lower_index - 1].upper_index = num;
                    if (ret < num - hash[num].lower_index + 1)
                        ret = num - hash[num].lower_index + 1;
                }
                else if (hash[num].upper_index != null_index){
                    hash[num - 1].upper_index = hash[num].upper_index;
                    hash[hash[num].upper_index + 1].lower_index = num;
                    if (ret < hash[num].upper_index - num + 1)
                        ret = hash[num].upper_index - num + 1;
                }
                else{
                    hash[num + 1].lower_index = num;
                    hash[num - 1].upper_index = num;
                    if (ret < 1)
                        ret = 1;
                }
                hash[num].is_checked = true;
            }
        }
        return ret;
    }
};
