struct Trie{
    Trie* child[26]={0};
    string word;
};
class Solution {
public:
    Trie* root;
    vector<string> ans;
    int DIRS[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    Trie* buildTrie(vector<string>& words){
        this->root=new Trie();
        for(string& s:words){
            Trie* cur=root;
            for(char& c:s){
                if(!cur->child[c-'a']){
                    cur->child[c-'a']=new Trie();
                }
                cur=cur->child[c-'a'];
            }
            cur->word=s;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int& x, int& y, Trie* cur){
        char c=board[x][y];
        int m=board.size(), n=board[0].size();
        if(c=='#'|| !cur->child[c-'a']) return;
        cur=cur->child[c-'a'];
        if(cur->word!=""){
            ans.push_back(cur->word);
            cur->word="";
        }
        board[x][y]='#';
        for(auto&[dx, dy]:DIRS){
            int X=x+dx, Y=y+dy;
            if(X>=0&& X<m&&
            Y>=0&& Y<n){
                dfs(board, X, Y, cur);
            }
        }
        board[x][y]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->root=buildTrie(words);
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};
