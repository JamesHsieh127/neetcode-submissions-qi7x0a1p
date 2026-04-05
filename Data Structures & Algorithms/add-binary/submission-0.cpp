class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size()-1, n=b.size()-1, carry=0;
        string ans="";
        while(m>=0 || n>=0){
            int x=0, y=0, sum=0;
            if(m>=0) x=a[m]-'0';
            if(n>=0) y=b[n]-'0';
            sum=x+y+carry;
            carry=sum/2;
            ans=to_string(sum%2)+ans;
            m--;
            n--;
        }
        return carry?"1"+ans:ans;
    }
};