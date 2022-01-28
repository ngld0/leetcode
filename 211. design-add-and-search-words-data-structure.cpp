class WordDictionary {
private :
  // storing the words by the length() of word.
    unordered_map<int,vector<string>> words;
    
    bool s_helper(string a, string b){
        for(int i = 0 ; i< a.length();i++){
            
            if(a[i] == '.' ) continue;
            
            if(a[i] != b[i]) return false;
        }
        
        return true;
    }
    
public:
    WordDictionary() {
        words = {};
    }
    
    void addWord(string word) {
        words[word.length()].push_back(word);
    }
    
    bool search(string word) {
        for(auto w : words[word.length()]){
            if(s_helper(word, w)) return true;
        }

        return false;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 /*
 Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
 
 */
