class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st, vis;
        for(string& s:deadends){
            st.insert(s);
        }
        if(st.contains("0000")) return 0;
        int ans=0;
        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        while(!q.empty()){
            ans++;
            int sz=q.size();
            for(int i=0; i<sz; i++){
                string s=q.front();
                q.pop();
                for(int j=0; j<4; j++){
                    int x=s[j]-'0'; 
                    for(int diff:{1, -1}){
                        char nxt=(x+diff+10)%10+'0';
                        s[j]=nxt;
                        if(s==target) return ans;
                        if(!st.contains(s)&&
                        !vis.contains(s)){
                            q.push(s);
                        }
                        vis.insert(s);
                    }
                    s[j]=x+'0';
                }
            }
        }
        return -1;
    }
};