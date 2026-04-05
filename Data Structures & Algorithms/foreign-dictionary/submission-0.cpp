class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indrgee;
        int n=words.size();
        for(auto& s:words){
            for(char& c:s){
                indrgee[c]=0;
            }
        }
        for(int i=0; i<n-1; i++){
            string a=words[i], b=words[i+1];
            int len=min(a.size(), b.size());
            if(a.size()>b.size()&& 
            a.substr(0, len)==b.substr(0, len)){
                return "";
            }
            for(int j=0; j<len; j++){
                if(a[j]!=b[j]){
                    if(!graph[a[j]].contains(b[j])){
                        graph[a[j]].insert(b[j]);
                        indrgee[b[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        string ans="";
        for(auto& [c, d]:indrgee){
            if(!d) q.push(c);
        }
        while(!q.empty()){
            char c=q.front();
            q.pop();
            ans+=c;
            for(char neighber:graph[c]){
                indrgee[neighber]--;
                if(!indrgee[neighber]){
                    q.push(neighber);
                }
            }
        }
        if(ans.size()!=indrgee.size()) return "";
        return ans;
    }
};
