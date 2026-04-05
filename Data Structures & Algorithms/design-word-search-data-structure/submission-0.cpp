struct Trie{
    Trie* child[26]={0};
    bool isEnd=false;
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root=new Trie();
    }
    bool dfs(string& word, int idx, Trie* cur){
        if(!cur) return false;
        int n=word.size();
        if(idx==n){
            return cur->isEnd;
        }
        char c=word[idx];
        if(c=='.'){
            for(auto& a:cur->child){
                if(dfs(word, idx+1, a)){
                    return true;
                }
            }
        }
        else{
            return dfs(word, idx+1, cur->child[c-'a']);
        }
        return false;
    }
    void addWord(string word) {
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
        return dfs(word, 0, root);
    }
};
