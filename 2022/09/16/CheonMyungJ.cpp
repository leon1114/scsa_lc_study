//Runtime: 671 ms, faster than 76.65% of C++ online submissions for Word Search II.
//Memory Usage: 13.1 MB, less than 50.33% of C++ online submissions for Word Search II.
//오우 이거 trie와 dfs의 조화로 참신한 문제구만
//문자 일단 trie에 다 등록시킨담에
//board 모든 위치를 시작점으로 dfs로 들어가면서 trie와 비교하며 

class Trie {
public:
    class Node {
    public:
        Node* key[26];
        bool check;
        int count;
        string st;
        Node() : check(false), count(0), st() { memset(key, 0, sizeof(Node*) * 26); }
    };
    Node* head;

    Trie() {
        head = new Node();
    }

    void insert(string word) {
        Node* temp = head;
        for (int i = 0; i < word.length(); i++) {
            if (temp->key[word[i] - 'a'] == nullptr) {
                temp->key[word[i] - 'a'] = new Node();
            }
            temp = temp->key[word[i] - 'a'];
            temp->count++;
        }
        temp->st = word;
        temp->check = true;
    }

    bool search(string word) {
        Node* temp = head;
        for (int i = 0; i < word.length(); i++) {
            if (temp->key[word[i] - 'a'] == nullptr) return false;
            temp = temp->key[word[i] - 'a'];
        }
        return temp->check;
    }

    bool startsWith(string prefix) {
        Node* temp = head;
        for (int i = 0; i < prefix.length(); i++) {
            if (temp->key[prefix[i] - 'a'] == nullptr) return false;
            temp = temp->key[prefix[i] - 'a'];
        }
        return true;
    }
};

class Solution {
    vector<string> ret_string;
    int check[12][12];
public:
    int dfs(vector<vector<char>>& board, Trie::Node* node, int x, int y) {
        if (node->key[board[y][x] - 'a'] == nullptr || check[y][x] == 1) return 0;
        Trie::Node* next = node->key[board[y][x] - 'a'];

        int sum = 0;
		    check[y][x] = 1;
        if (x != board[0].size() - 1) {
            sum += dfs(board, next, x + 1, y);
        }
        if (x != 0) {
            sum += dfs(board, next, x - 1, y);
        }
        if (y != board.size() - 1) {
            sum += dfs(board, next, x, y + 1);
        }
        if (y != 0) {
            sum += dfs(board, next, x, y - 1);
        }
        next->count -= sum;

        if (next->check == true && next->count > 0) {
            next->check = false;
            next->count--;
            ret_string.push_back(next->st);
            sum++;
        }
        
        check[y][x] = 0;
        return sum;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tree;
        for (int i = 0; i < words.size(); i++) {
            tree.insert(words[i]);
        }
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[0].size(); x++) {
                dfs(board, tree.head, x, y);
            }
        }
        return ret_string;
    }
};
