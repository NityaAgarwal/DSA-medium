//https://leetcode.com/problems/implement-trie-prefix-tree/description/

class TrieNode {
    public: 
        TrieNode* next[26]; //representing 26 letters of the alphabet
        bool word_end;
        TrieNode () {
            //constructor
            for (auto &a : next) a = nullptr;
            word_end = false;
        }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (!p->next[index]) {
                p->next[index] = new TrieNode();
            }
            p = p->next[index];
        }
        p->word_end = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode* p = root;
        for (int i = 0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (p->next[index]) p = p->next[index];
            else return false;
        }
        if (!prefix) return p->word_end;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
