class Solution {
public:
    int getSum(int a, int b) {
        if(!b) return a;
        if(!a) return b;
        int carry=0;
        while(b){
            carry=((a&b)<<1);
            a^=b;
            b=carry;
        }
        return a;
    }
};
