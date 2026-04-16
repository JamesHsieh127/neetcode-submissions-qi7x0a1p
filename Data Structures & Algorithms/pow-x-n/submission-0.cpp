class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==1.0 || x==0) return x;
        long long lln=n;
        double ans=1.0;
        if(lln<0){
            lln=-lln;
            x=1/x;
        }
        while(lln){
            ans*=x;
            lln--;
        }
        return ans;
    }
};
