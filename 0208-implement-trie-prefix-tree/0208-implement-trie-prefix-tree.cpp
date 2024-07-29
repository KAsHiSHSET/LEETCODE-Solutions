class TrieNode {   
public:
    TrieNode *childNode[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : childNode) a = nullptr;
    }
};
class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word) {

        TrieNode* currNode = root;

        for (auto c : word) {
            if (currNode->childNode[c - 'a'] == NULL) {
                TrieNode* node = new TrieNode();
                currNode->childNode[c - 'a'] = node;
            }
            currNode = currNode->childNode[c-'a'];
        }
        currNode->isWord = 1;
    }

    bool search(string word) {
        TrieNode* currNode = root;
        for (auto c : word) {
            if (currNode->childNode[c - 'a'] == NULL) return false;
            else currNode=currNode->childNode[c - 'a'];
        }
        if (currNode->isWord == 1) return true;
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for (auto c : prefix) {
            if (currNode->childNode[c - 'a'] == NULL)   return false;
            else currNode= currNode->childNode[c - 'a'];
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