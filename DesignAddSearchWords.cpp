//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

// do this after ImplementTrie question for better understanding
class TrieNode {
    public:
    TrieNode* next[26];
    bool wordEnd;
    TrieNode () {
        for (auto &a : next) a = nullptr;
        wordEnd = false;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i<word.size(); i++) {
            int index = word[i] - 'a';
            if (!p->next[index]) p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p-> wordEnd = true;
    }
    
    bool search(string word, TrieNode* x = nullptr, int init = 0) {
        TrieNode* p;
        int i;
        if (x == nullptr) {
            p = root;
            i = 0;
        }
        else {
            p = x;
            i = init;
        }

        for(; i<word.size(); i++) {
            if (word[i] != '.') {
                int index = word[i] - 'a';
                if (!p->next[index]) return false;
                p = p->next[index];
            }
            else {
                for(int j = 0; j<26; j++) {
                    if (p->next[j] && search(word, p->next[j], i+1)) {
                        return true;
                    } 
                }
                return false;
            } 
        }
        return p->wordEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
