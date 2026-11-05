class Solution {
public:
    string findKthBit(int n, int k) {
        if(k==1) return "0";
        if(n==1) return "1";
        int sz=(1<<n)-1;
        int mid=(sz+1)/2;
        if(k==mid) return "1";
        if(k<mid){
            return findKthBit(n-1,k);
        }
        string c=findKthBit(n-1, sz-k+1);
        return (c=="0")?"1":"0";
    }
};
