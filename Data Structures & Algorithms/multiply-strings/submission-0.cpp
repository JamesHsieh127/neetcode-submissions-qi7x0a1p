class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string ans="";
        int m=num1.size(), n=num2.size();
        vector<int> vals(m+n, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int sum=(num1[i]-'0')*(num2[j]-'0')+vals[i+j+1];
                vals[i+j+1]=sum%10;
                vals[i+j]+=sum/10;
            }
        }
        for(int x:vals){
            if(!ans.empty()|| x){
                ans+=(x+'0');
            }
        }
        return ans;
    }
};
