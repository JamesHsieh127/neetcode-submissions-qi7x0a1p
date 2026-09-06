class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size(), sum=0;
        vector<int> prefix(n,0), suffix(n,0), ans(n,0);
        for(int i=0; i<n; i++){
            if(i>0){
                prefix[i]=prefix[i-1]+sum;
            }
            if(boxes[i]=='1') sum++;
        }
        sum=0;
        for(int i=n-1; i>=0; i--){
            if(i<n-1){
                suffix[i]=suffix[i+1]+sum;
            }
            if(boxes[i]=='1') sum++;
        }
        for(int i=0; i<n; i++){
            ans[i]=prefix[i]+suffix[i];
        }
        return ans;
    }
};