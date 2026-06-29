class Solution {
public:
    string decodeString(string s) {
        stack<string> strStk;
        stack<int> intStk;
        int x=0;
        string t="";
        for(char& c:s){
            if(c>='0'&&c<='9'){
                x=x*10+(c-'0');
            }
            else if(c=='['){
                strStk.push(t);
                t="";
                intStk.push(x);
                x=0;
            }
            else if(c==']'){
                int num=intStk.top();
                intStk.pop();
                string temp=strStk.top();
                strStk.pop();
                for(int i=0; i<num; i++){
                    temp+=t;
                }
                t=temp;
            }
            else t+=c;
        }
        if(strStk.empty()) return t;
        return strStk.top();
    }
};