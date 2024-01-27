class TrieNode {

public:
    // data memebers
  
    TrieNode* child[26];
    bool terminal;

    TrieNode() {
   
        terminal = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string s) {
        int i = 0, n = s.length();
        TrieNode* node = root;
        while (i < n) {
            if (node->child[s[i] - 'a'] != NULL) {
                node = node->child[s[i] - 'a'];
                i++;
            } else {
                TrieNode* newnode = new TrieNode();
                node->child[s[i] - 'a'] = newnode;
                node = node->child[s[i] - 'a'];
                i++;
            }
        }
        node->terminal = true;
    }

    bool f(int i,string &s,TrieNode*node){

        if(i>=s.length()){
            return node->terminal;
        }


        if(s[i]=='.'){
            for(char ch='a';ch<='z';ch++){
                if(node->child[ch-'a']!=NULL){
                    if(f(i+1,s,node->child[ch-'a'])){
                        return true;
                    }
                }
            }

            return false;
        }
        else if(node->child[s[i]-'a']){
            return f(i+1,s,node->child[s[i]-'a']);
        }

        else return false;
    }

    bool search(string s) {
        return f(0,s,root);
    }

};
class WordDictionary {
    Trie t;
public:
    WordDictionary() {
    }

    void addWord(string word) {
        t.insert(word);
    }

    bool search(string word) {
        return t.search(word);
    }
};
