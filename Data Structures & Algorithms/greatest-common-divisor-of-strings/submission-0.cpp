class Solution {
public:
    bool isValid(string t, string s){
        int m=t.size(), n=s.size();
        if(n%m!=0) return false;
        for(int i=0; i<n; i++){
            if(s[i]!=t[i%m]) return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int m=str1.size(), n=str2.size();
        for(int i=min(m,n); i>=1; i--){
            if(m%i==0 && n%i==0){
                string ans=str1.substr(0, i);
                if(isValid(ans, str1)&& isValid(ans, str2)){
                    return ans;
                }
            }
        }
        return "";
    }
};