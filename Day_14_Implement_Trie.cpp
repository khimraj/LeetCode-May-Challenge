/* Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings. */


class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        bool end = false;
        Node *next[26] = {NULL};
    }*head;
    Trie() {
        head = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *ptr = head;
        for (char c : word) {
            if (ptr->next[c-'a'] == NULL) {
                ptr->next[c-'a'] = new Node;
            }
            ptr = ptr->next[c-'a'];
        }
        ptr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *ptr = head;
        for (char c : word) {
            if( ptr->next[c - 'a'] == NULL) {
                return false;
            }
            ptr = ptr->next[c - 'a'];
        }
        return ptr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *ptr = head;
        for (char c : prefix) {
            if( ptr->next[c - 'a'] == NULL) {
                return false;
            }
            ptr = ptr->next[c - 'a'];
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