// Runtime: 115 ms, faster than 41.15% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 45.2 MB, less than 30.81% of C++ online submissions for Implement Trie (Prefix Tree).

struct Node {
    Node * ch[26];
    bool end;
};

class Trie {
public:
    Node*root, *cur;
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
    
    bool search(string word) {
        int len = word.length();
        cur = root;
        for(int i = 0; i < len; i++) {
            if (cur->ch[word[i] - 'a'] == 0) return false;
            cur = cur->ch[word[i] - 'a'];
        }
        if (cur->end == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        int len = prefix.length();
        cur = root;
        for(int i = 0; i < len; i++) {
            if (cur->ch[prefix[i] - 'a'] == 0) return false;
            cur = cur->ch[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
