class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size(), ri=0, wi=0;
        while(ri<n){
            char c=chars[ri];
            int cnt=0;
            while(ri<n&&
            chars[ri]==c){
                cnt++;
                ri++;
            }
            chars[wi]=c;
            wi++;
            if(cnt>1){
                for(char x:to_string(cnt)){
                    chars[wi]=x;
                    wi++;
                }
            }
        }
        return wi;
    }
};