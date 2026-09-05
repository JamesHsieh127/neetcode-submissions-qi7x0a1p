class Solution {
public:
    vector<string> split(string& s, char c){
        vector<string> ans;
        stringstream ss(s);
        string t;
        while(getline(ss, t, c)){
            ans.push_back(t);
        }
        return ans;
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> mp;
        int n=username.size();
        for(int i=0; i<n; i++){
            mp[username[i]].push_back({timestamp[i], website[i]});
        }
        unordered_map<string, int> cnt;
        for(auto&[time, web]:mp){
            int sz=web.size();
            unordered_set<string> st;
            if(sz>2){
                sort(web.begin(), web.end());
                for(int i=0; i<sz-2; i++){
                    for(int j=i+1; j<sz-1; j++){
                        for(int k=j+1; k<sz; k++){
                            st.insert(web[i].second+","+web[j].second+","+web[k].second);
                        }
                    }
                }
            }
            for(auto& a:st) cnt[a]++;
        }
        int maxVal=0;
        string ans="";
        for(auto&[s, freq]:cnt){
            if(maxVal<freq||
            (maxVal==freq && ans>s)){
                maxVal=freq;
                ans=s;
            }
        }
        return split(ans, ',');
    }
};