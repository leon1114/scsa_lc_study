

// 그제 문제에서 츄라이 갖고옴
struct Node {
    Node * ch[26];
    bool end;
};

class Trie {
public:
    Node *root, *cur;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        int len = word.length();
        cur = root;
        for(int i = 0; i < len; i++) {
            if (cur->ch[word[i] - 'a'] == 0) cur->ch[word[i] - 'a'] = new Node();
            cur = cur->ch[word[i] - 'a'];
        }
        // end to true
        cur->end = true;
    }
};

struct BoardNode {
    Node * node;
    int i, j;
    string str;
};

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        vector<string> res;
        queue<BoardNode> q;
        Trie* dict = new Trie();
        Node *root = dict->root;
        Node *cur = root;
        // fill up the dictionary first
        int len = words.size();
        for(int i = 0; i < len; i++) {
            dict->insert(words[i]);
        }
        
        BoardNode* tmp;
        // add starting points to queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (root->ch[board[i][j] - 'a'] == 0) continue; // char not in dict
                tmp = new BoardNode();
                tmp->node = root->ch[board[i][j] - 'a'];
                tmp->i = i; tmp->j = j;
                tmp->str.push_back(board[i][j]);
                q.push(*tmp);
            }
        }
        
        int check[m][n] = {0,};
        
        // run bfs+dfs
        while(!q.empty()){
            BoardNode cur = q.front();
            q.pop();
            
            dfs(cur, )
            // 지금까지 나온 단어가 end == true면 res에 값추가하기
            if (cur.node->end) {
                cur.node->end = false;
                res.push_back(cur.str);
            }
            check[i][j] = 1;
            // 4방향으로 돌리면서 조건 맞으면 q에 넣기
            for (int a = 0; a < 4; a++) {
                int ni = cur.i + dir[a][0];
                int nj = cur.j + dir[a][1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n ||
                    cur.node->ch[board[ni][nj] - 'a'] == 0 || check[ni][nj]) continue;
                tmp = new BoardNode();
                tmp->node = cur.node->ch[board[ni][nj] - 'a'];
                tmp->i = ni; tmp->j = nj;
                tmp->str = cur.str;
                tmp->str.push_back(board[ni][nj]);
                q.push(*tmp);
            }
            check[i][j] = 0;
        }

        
        
        // 백트래킹으로 했으면 됐을텐데..
        // run bfs.
        return res;
    }
};

