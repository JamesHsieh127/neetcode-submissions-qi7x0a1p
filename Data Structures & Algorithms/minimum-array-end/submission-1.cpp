class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x, target=n-1, bit=0;
        for(int i=0; i<64; i++){
            if(((ans>>i)&1)==0){
                if((target>>bit)&1){
                    ans|=(1LL<<i);
                }
                bit++;
            }
        }
        return ans;
    }
};