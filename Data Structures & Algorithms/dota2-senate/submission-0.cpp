class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR, qD;
        int n=senate.size();
        for(int i=0; i<n; i++){
            if(senate[i]=='R') qR.push(i);
            else qD.push(i);
        }
        while(!qR.empty()&& !qD.empty()){
            int idxR=qR.front(), idxD=qD.front();
            qR.pop();
            qD.pop();
            (idxR<idxD)?qR.push(idxR+n):qD.push(idxD+n);
        }
        return (qR.size()>qD.size())?"Radiant":"Dire";
    }
};