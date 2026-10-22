class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes="L"+dominoes+"R";
        int left=0, n=dominoes.size();
        string ans="";
        for(int right=1; right<n; right++){
            if(dominoes[right]=='.') continue;
            if(left!=0) ans+=dominoes[left];
            int mid=right-left-1;
            if(dominoes[left]==dominoes[right]){
                ans+=string(mid, dominoes[left]);
            }
            else if(dominoes[left]=='L'&&
            dominoes[right]=='R'){
                ans+=string(mid, '.');
            }
            else{
                ans+=(string(mid/2, 'R')+(mid%2==1?".":"")+string(mid/2, 'L'));
            }
            left=right;
        }
        return ans;
    }
};