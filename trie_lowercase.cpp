
class Trie {
  public:
    class TrieNode {
      public:
        array<TrieNode*,26> child;
        bool isEnd;
    };
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* cur = root;
        for(char c: word){
            if(cur->child[c-'a'] == nullptr){
                cur->child[c-'a'] = new TrieNode();
            }
            cur = cur->child[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(const string& word) {
        TrieNode* cur = root;
        for(char c: word){
            if(cur->child[c-'a'] == nullptr){
                return false;
            }
            cur = cur->child[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(const string& prefix) {
        TrieNode* cur = root;
        for(char c: prefix){
            if(cur->child[c-'a'] == nullptr){
                return false;
            }
            cur = cur->child[c-'a'];
        }
        return true;
    }
    TrieNode* root;
};
