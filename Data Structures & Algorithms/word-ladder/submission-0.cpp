class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> st, curSt;
        for(string& s:wordList) st.insert(s);
        while(!q.empty()){
            int sz=q.size();
            ans++;
            for(int i=0; i<sz; i++){
                string cur=q.front();
                q.pop();
                if(cur==endWord){
                    return ans;
                }
                int n=cur.size();
                string nxt=cur;
                for(char c='a'; c<='z'; c++){
                    for(int j=0; j<n; j++){
                        nxt[j]=c;
                        if(st.contains(nxt)&&
                        !curSt.contains(nxt)){
                            curSt.insert(nxt);
                            q.push(nxt);
                        }
                        nxt=cur;
                    }
                }
            }
        }
        return 0;
    }
};
