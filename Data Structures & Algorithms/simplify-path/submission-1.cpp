class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string ans="", s="";
        istringstream ss(path);
        while(getline(ss, s, '/')){
            if(s.empty()||s=="."){
                continue;
            }
            if(s!=".."){
                stk.push_back(s);
            }
            else if(!stk.empty()){
                stk.pop_back();
            }
        }
        for(string& s:stk){
            ans+='/';
            ans+=s;
        }
        return ans.empty()?"/":ans;
    }
};