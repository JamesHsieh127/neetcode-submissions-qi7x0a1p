class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        stack<char> stk;
        for(char& c:s){
            if(c=='[') stk.push(c);
            else{
                if(!stk.empty()) stk.pop();
                else cnt++;
            }
        }
        return (cnt+1)/2;
    }
};