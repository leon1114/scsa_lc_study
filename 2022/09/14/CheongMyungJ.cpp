//Runtime: 70 ms, faster than 84.81% of C++ online submissions for Implement Trie (Prefix Tree).
//Memory Usage: 45 MB, less than 69.16% of C++ online submissions for Implement Trie (Prefix Tree).
//오 슥사때 배웠던 트라이.. 기억에 남아있네 용케ㅋㅋ

class Trie {
    class Node{
        public:
        Node* key[26];
        bool check;
        Node() : check(false) { memset(key, 0, sizeof(Node*)*26); }
    };
    Node* head;
public:
    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* temp = head;
        for (int i = 0; i < word.length(); i++){
            if (temp->key[word[i]-'a'] == nullptr){
                temp->key[word[i]-'a'] = new Node();
            }
            temp = temp->key[word[i]-'a'];
        }
        temp->check = true;
    }
    
    bool search(string word) {
        Node* temp = head;
        for (int i = 0; i < word.length(); i++){
            if (temp->key[word[i]-'a'] == nullptr) return false;
            temp = temp->key[word[i]-'a'];
        }
        return temp->check;
    }
    
    bool startsWith(string prefix) {
        Node* temp = head;
        for (int i = 0; i < prefix.length(); i++){
            if (temp->key[prefix[i]-'a'] == nullptr) return false;
            temp = temp->key[prefix[i]-'a'];
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
