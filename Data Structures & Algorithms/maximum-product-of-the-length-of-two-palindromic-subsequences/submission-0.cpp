class Solution {
public:
    bool isPalindrome(string& s){
        int left=0, right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    int maxProduct(string s) {
        int n=s.size();
        int total=1<<n;
        vector<int> palindromes, maskSz;
        for(int mask=1; mask<total; mask++){
            string subs="";
            for(int i=0; i<n; i++){
                if(mask&(1<<i)){
                    subs+=s[i];
                }
            }
            if(isPalindrome(subs)){
                palindromes.push_back(mask);
                maskSz.push_back(subs.size());
            }
        }
        int ans=0, m=palindromes.size();
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                if((palindromes[i]&palindromes[j])==0){
                    ans=max(ans, maskSz[i]*maskSz[j]);
                }
            }
        }
        return ans;
    }
};