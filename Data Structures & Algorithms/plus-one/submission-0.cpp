class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1, n=digits.size();
        for(int i=n-1; i>=0; i--){
            if(digits[i]<9 && carry==1){
                digits[i]++;
                carry=0;
                break;
            }
            else{
                digits[i]=0;
                carry=1;
            }
        }
        if(carry){
            vector<int> ans={1};
            for(int& x:digits){
                ans.push_back(x);
            }
            return ans;
        }
        return digits;
    }
};
