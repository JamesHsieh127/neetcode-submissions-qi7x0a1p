class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26, 0);
        int m=words.size(), n=order.size();
        for(int i=0; i<n; i++){
            mp[order[i]-'a']=i;
        }
        for(int i=1; i<m; i++){
            bool isUsed=false;
            for(int j=0; j<words[i-1].size()&& j<words[i].size(); j++){
                int prev=mp[words[i-1][j]-'a'];
                int cur=mp[words[i][j]-'a'];
                if(prev<cur){
                    isUsed=true;
                    break;
                }
                else if(prev>cur) return false;
            }
            if(!isUsed){
                if(words[i-1].size()>words[i].size()){
                    return false;
                }
            }
        }
        return true;
    }
};