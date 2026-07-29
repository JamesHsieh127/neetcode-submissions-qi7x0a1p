class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int, char>> maxHeap;
        if(a>0) maxHeap.push({a, 'a'});
        if(b>0) maxHeap.push({b, 'b'});
        if(c>0) maxHeap.push({c, 'c'});
        while(!maxHeap.empty()){
            int n=ans.size();
            auto [cnt, c]=maxHeap.top();
            maxHeap.pop();
            if(n<=1){
                ans+=c;
                cnt--;
                if(cnt>0){
                    maxHeap.push({cnt, c});
                }
            }
            else{
                if(ans.back()==c&& ans[n-2]==c){
                    if(maxHeap.empty()) break;
                    auto [nxtCnt, nxtC]=maxHeap.top();
                    maxHeap.pop();
                    ans+=nxtC;
                    nxtCnt--;
                    if(cnt>0){
                        maxHeap.push({cnt, c});
                    }
                    if(nxtCnt>0){
                        maxHeap.push({nxtCnt, nxtC});
                    }
                }
                else{
                    ans+=c;
                    cnt--;
                    if(cnt>0){
                        maxHeap.push({cnt, c});
                    }
                }
            }
        }
        return ans;
    }
};