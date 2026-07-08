class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size(), n=word2.size(), i=0, j=0;
        string ans="";
        if(m==0) return word2;
        if(n==0) return word1;
        while(i<m||j<n){
            if(i<m){
                ans+=word1[i];
                i++;
            }
            if(j<n){
                ans+=word2[j];
                j++;
            }
        }
        return ans;
    }
};