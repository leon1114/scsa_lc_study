/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//Runtime: 46 ms, faster than 43.92% of C++ online submissions for Merge k Sorted Lists.
//Memory Usage: 13.3 MB, less than 72.97% of C++ online submissions for Merge k Sorted Lists.
//20001 크기를 갖는 카운트소트 array 2개를 만들어서 모든 링크드리스트 데이터 읽으면서 val 별 node의 시작점, 끝점을 저장해놓음 O(n)
//20001번 돌면서 begin_arr에 값이 있다면(인덱스를 val로 갖는 node가 있다면) 이전 val의 끝점과 이번 val의 시작점을 연결. O(m)
//최종적으로 O(n+m)으로 해결 가능. 여기서 n은 sum of lists[i].length (Max 10000), m은 20001

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* begin_arr[20010] = {0,};
        ListNode* end_arr[20010] = {0,};
        int len = lists.size();
        for (int i = 0; i < len; i++){
            ListNode* node = lists[i];
            while(node != nullptr){
                if (begin_arr[node->val + 10000] == 0){
                    begin_arr[node->val + 10000] = node;
                    end_arr[node->val + 10000] = node;
                }
                else{
                    end_arr[node->val + 10000]->next = node;
                    end_arr[node->val + 10000] = node;
                }
                node = node->next;
            }
        }
        ListNode* ret_node = nullptr;
        ListNode* temp_end_node = nullptr;
        for (int i = 0; i <= 20000; i++){
            if (ret_node == nullptr && begin_arr[i] != 0){
                ret_node = begin_arr[i];
                temp_end_node = end_arr[i];
            }
            else if (ret_node != nullptr && begin_arr[i] != 0){
                temp_end_node->next = begin_arr[i];
                temp_end_node = end_arr[i];
            }
        }
        return ret_node;
    }
};
