class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(word==abbr) return true;
        int m=word.size(), n=abbr.size(), i=0, j=0, x=0;
        while(i<m&& j<n){
            if(isdigit(abbr[j])){
                if(abbr[j]=='0'&&x==0){
                    return false;
                }
                x=x*10+(abbr[j]-'0');
            }
            else{
                i+=x;
                x=0;
                if(i>=m||
                word[i]!=abbr[j]){
                    return false;
                }
                i++;
            }
            j++;
        }
        return i+x==m&& j==n;
    }
};