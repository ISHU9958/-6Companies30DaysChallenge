
class TrieNode {

public:
    // data memebers
    char val;
    TrieNode* child[26];
    bool terminal;

    TrieNode(char ch) {
        val = ch;
        terminal = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode('\0'); }

    void insert(string s) {
        int i = 0, n = s.length();
        TrieNode* node = root;
        while (i < n) {
            if (node->child[s[i] - 'a'] != NULL) {
                node = node->child[s[i] - 'a'];
                i++;
            } else {
                TrieNode* newnode = new TrieNode(s[i]);
                node->child[s[i] - 'a'] = newnode;
                node = node->child[s[i] - 'a'];
                i++;
            }
        }
        node->terminal = true;
    }

    bool search(string s) {
        int i = 0, n = s.length();
        TrieNode* node = root;
        while (i < n) {
            if (node->child[s[i] - 'a'] != NULL) {
                node = node->child[s[i] - 'a'];
                i++;
            } else {
                return false;
            }
        }
        return node->terminal;
    }



};
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        for(int i=0;i<startWords.size();i++){
            
            sort(startWords[i].begin(),startWords[i].end());
        }
        for(int i=0;i<targetWords.size();i++){
            
            sort(targetWords[i].begin(),targetWords[i].end());
        }
        Trie tr;
        for(auto &st:startWords){
            tr.insert(st);
        }

        int ans=0;
        for(auto &st:targetWords){
            for(int i=0;i<st.size();i++){
                string temp=st.substr(0,i)+st.substr(i+1);
                if(tr.search(temp)){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
