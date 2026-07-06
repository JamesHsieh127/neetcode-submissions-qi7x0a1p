class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for(auto& x:asteroids){
            bool isAlive=true;
            while(!stk.empty()&& isAlive&& stk.back()>0 && x<0){
                if(stk.back()<abs(x)){
                    stk.pop_back();
                }
                else if(stk.back()==abs(x)){
                    stk.pop_back();
                    isAlive=false;
                }
                else{
                    isAlive=false;
                }
            }
            if(isAlive) stk.push_back(x);
        }
        return stk;
    }
};