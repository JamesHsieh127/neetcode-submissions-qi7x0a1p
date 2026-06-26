class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5) return false;
        int cnt5=0, cnt10=0;
        for(int& x:bills){
            if(x==5){
                cnt5++;
            }
            else if(x==10){
                cnt5--;
                cnt10++;
            }
            else{
                if(cnt10){
                    cnt10--;
                    cnt5--;
                }
                else{
                    cnt5-=3;
                }
            }
            if(cnt5<0) return false;
        }
        return true;
    }
};