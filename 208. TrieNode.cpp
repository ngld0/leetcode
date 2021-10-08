class Node{
    public: 
    bool isWord;
    Node * child[26];
    Node():isWord(false){
        
        for (auto &a:child) a = nullptr;
    }
};


class Trie {
public:
    Trie() {
        root = new Node();        
    }
    
    void insert(string word) {
        Node* p = root;
        for(auto &w: word){
            int i = w - 'a';
            if(!p-> child[i]) p->child[i] = new Node();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        Node* p = root;
        for(auto &w: word){
            int i = w - 'a';
            if(!p-> child[i]) return false;
            p = p->child[i];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
       Node* p = root;
        for(auto &w: prefix){
            int i = w - 'a';
            if(!p-> child[i]) return false;
            p = p->child[i];
        }
        return true;
    }
    private:
        Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.

*/
