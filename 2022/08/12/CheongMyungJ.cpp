// Runtime: 1556 ms, faster than 20.89% of C++ online submissions for Word Ladder.
// Memory Usage: 31.6 MB, less than 17.20% of C++ online submissions for Word Ladder.
// 너무 거지같이 느려서 다시해봐야겠음.. bfs로 풀었음. 한번 간 string은 다시 안봐도 되니 체크하고

class Solution {
    struct st {
        string str;
        int depth;
        st(string a, int d) :str(a), depth(d) {}
    };

public:
    int sol;

    int bfs(string& endWord, string& word, unordered_map<string, list<string>>& hash) {
        unordered_map<string, int> check;
        queue<st> q;
        q.push(st(word, 1));
        check[word] = 1;

        
        while (q.size()) {
            st data = q.front();
            q.pop();
            
            list<string> lst = hash[data.str];
            list<string>::iterator iter = lst.begin();
            while (iter != lst.end()) {
                if (*iter == endWord) return data.depth + 1;
                if (check.count(*iter) == 1) {
                    iter++;
                    continue;
                }
                q.push(st(*iter, data.depth + 1));
                check[*iter] = 1;
                iter++;
            }
        }
        return sol;
    }
    bool isSimilar(string& a, string& b) {
        int diff_count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) diff_count++;
        }
        if (diff_count == 1) return true;
        else return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sol = 0;
        
        unordered_map<string, list<string>> hash;

        bool is_end_contains = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (endWord == wordList[i]) is_end_contains = true;
            hash[wordList[i]] = list<string>();
        }
        if (is_end_contains == false) return 0;
        wordList.push_back(beginWord);
        hash[beginWord] = list<string>();

        for (int i = 0; i < wordList.size() - 1; i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (isSimilar(wordList[i], wordList[j])) {
                    hash[wordList[i]].push_back(wordList[j]);
                    hash[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        return bfs(endWord, beginWord, hash);
    }
};
