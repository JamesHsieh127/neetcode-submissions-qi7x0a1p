struct Trie{
    Trie* child[26]={0};
    bool isEnd=false;
};
class PrefixTree {
public:
    Trie* root;
    PrefixTree() {
        root=new Trie();
    }
    
    void insert(string word) {
        Trie* cur=root;
        for(char c:word){
            if(!cur->child[c-'a']){
                cur->child[c-'a']=new Trie();
            }
            cur=cur->child[c-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        Trie* cur=root;
        for(char c:word){
            if(!cur->child[c-'a']){
                return false;
            }
            cur=cur->child[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* cur=root;
        for(char c:prefix){
            if(!cur->child[c-'a']){
                return false;
            }
            cur=cur->child[c-'a'];
        }
        return true;
    }
};
