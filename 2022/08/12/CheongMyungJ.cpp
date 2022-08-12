// 늦퇴해서 시간없어서 체크만 걸어둠 ㅠ 아래 코드는 timelimit exceeded..
// bfs, dfs 둘다해봄





class Solution {
    struct st {
        string str;
        int depth;
        st(string a, int d) :str(a), depth(d) {}
    };

public:
    int sol;

    int bfs(string& endWord, string& word, unordered_map<string, list<string>>& hash) {
        queue<st> q;
        q.push(st(word, 1));

        while (q.size()) {
            st data = q.front();
            q.pop();

            if (data.str == endWord)
                return data.depth;

            list<string> lst = hash[data.str];
            list<string>::iterator iter = lst.begin();
            while (iter != lst.end()) {
                q.push(st(*iter, data.depth + 1));
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



class Solution {
public:
    int sol;

    void dfs(string& endWord, string& word, unordered_map<string, list<string>>& hash, unordered_map<string, int>& depth_hash, int depth) {
        if (sol <= depth) return;
        if (word == endWord) {
            sol = depth;
            return;
        }
        list<string> temp_list;
        list<string> lst = hash[word];
        list<string>::iterator iter = lst.begin();
        while (iter != lst.end()) {
            int sub_depth = depth_hash[*iter];
            if (sub_depth <= depth + 1) {
                iter++;
                continue;
            }
            depth_hash[*iter] = depth + 1;
            temp_list.push_back(*iter);
            iter++;
        }
        iter = temp_list.begin();
        while (iter != temp_list.end()) {
            dfs(endWord, *iter, hash, depth_hash, depth + 1);
            iter++;
        }


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
        sol = 5001;
        
        unordered_map<string, list<string>> hash;
        unordered_map<string, int> depth_hash;

        bool is_end_contains = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (endWord == wordList[i]) is_end_contains = true;
            hash[wordList[i]] = list<string>();
            depth_hash[wordList[i]] = 5001;
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
        depth_hash[beginWord] = 1;
        dfs(endWord, beginWord, hash, depth_hash, 1);
        
        return sol == 5001? 0 : sol;
    }
};
