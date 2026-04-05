class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<int, unordered_set<char>> graph;
        unordered_map<char, int> indeg;
        int n=words.size();
        for(auto& s:words){
            for(char& c:s){
                indeg[c]=0;
            }
        }
        for(int i=0; i<n-1; i++){
            string a=words[i], b=words[i+1];
            int m=min(a.size(), b.size());
            if((a.size()>b.size())&&
            (a.substr(0, m)==b.substr(0, m))){
                return "";
            }
            for(int j=0; j<m; j++){
                if(a[j]!=b[j]){
                    if(!graph[a[j]].contains(b[j])){
                        graph[a[j]].insert(b[j]);
                        indeg[b[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for(auto&[c, deg]:indeg){
            if(deg==0) q.push(c);
        }
        string ans;
        while(!q.empty()){
            char x=q.front();
            q.pop();
            ans+=x;
            for(char nxt:graph[x]){
                indeg[nxt]--;
                if(indeg[nxt]==0){
                    q.push(nxt);
                }
            }
        }
        if(ans.size()==indeg.size()){
            return ans;
        }
        return "";
    }
};
