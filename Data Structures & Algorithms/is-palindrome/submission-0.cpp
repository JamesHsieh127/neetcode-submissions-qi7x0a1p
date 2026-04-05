class Solution {
public:
    bool isPalindrome(string s) {
        string pureS="";
        for(char c:s){
            if(isalpha(c)){
                pureS+=tolower(c);
            }
            else if(isdigit(c)){
                pureS+=c;
            }
        }
        int left=0, right=pureS.size()-1;
        while(left<right){
            if(pureS[left]!=pureS[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
