class Solution {
public:
    unordered_set<int> st;
    bool isHappy(int n) {
        while(n!=1){
            int x=0;
            while(n){
                x+=(n%10)*(n%10);
                n/=10;
            }
            if(st.contains(x)) break;
            else st.insert(x);
            n=x;
        }
        return n==1;
    }
};
