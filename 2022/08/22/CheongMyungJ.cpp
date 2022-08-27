// Runtime: 610 ms, faster than 66.87% of C++ online submissions for LRU Cache.
// Memory Usage: 164.5 MB, less than 94.82% of C++ online submissions for LRU Cache.
// 뭐여 이런문제도 나오는거였어?ㅋㅋㅋ 
// 오랜만에 삼성 서티스타일 나와서 신기하네
// 중요한건 가장 접근한지 오래된 놈을 찾아서 그놈을 삭제하고 새로운 key value를 추가하는 부분.
// 이걸 key_queue, key_count로 처리할거임
// get(return -1 제외), put의 경우에 항상 접근 업데이트가 되기 때문에 key_queue에다 push(key)를 해줌.
// 그러면서 key_count[key]의 갯수도 ++ 해줄거임
// 이렇게 되면 queue.front에는 가장 오래된 놈이 있을텐데, 사실 예외케이스가 하나 있음
// queue.front이지만 중간에 언젠가 업데이트가 돼서 queue에 또 들어간 경우임.
// 하지만 그런 경우라면 key_count[key]가 분명 2 이상일거임
// 따라서 이런 경우엔 key_count[key]--를 해주고 queue.pop()을 해주면서 다음으로 가장 오래된 놈을 봄 (45~48 line)
// 이 작업을 반복하면서 key_count[key] == 1인 경우는 진짜로 가장 오래된 놈이니 이놈 지우고 새로운놈 추가.


class LRUCache {
private:
    unordered_map<int, int> hash;
    queue<int> key_queue;
    int key_count[10001];
    int max_size;
    int size;
public:
    LRUCache(int capacity) {
        hash.clear();
        while(key_queue.empty() == false)
            key_queue.pop();
        for (int i = 0; i < 10001; i++)
            key_count[i] = 0;
        max_size = capacity;
        size = 0;
    }

    int get(int key) {
        if (hash.count(key) == 1) {
            key_queue.push(key);
            key_count[key]++;
            return hash[key];
        }
        else return -1;
    }

    void put(int key, int value) {
        if (max_size == size && hash.count(key) == 0) {
            while (key_count[key_queue.front()] > 1) {
                key_count[key_queue.front()]--;
                key_queue.pop();
            }
            hash.erase(key_queue.front());
            key_count[key_queue.front()] = 0;
            key_queue.pop();
        }
        else {
            if (hash.count(key) == 0)
                size++;
        }
        hash[key] = value;
        key_queue.push(key);
        key_count[key]++;

    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
