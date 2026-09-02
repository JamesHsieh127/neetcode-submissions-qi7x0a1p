class Solution {
public:
    const string VOWEL="aeiou";
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m=words.size(), n=queries.size();
        vector<int> prefix(m+1, 0), ans(n, 0);
        for(int i=0; i<m; i++){
            prefix[i+1]=prefix[i];
            if(VOWEL.contains(words[i][0])&&
            VOWEL.contains(words[i].back())){
                prefix[i+1]++;
            }
        }
        for(int i=0; i<n; i++){
            ans[i]=prefix[queries[i][1]+1]-prefix[queries[i][0]];
        }
        return ans;
    }
};