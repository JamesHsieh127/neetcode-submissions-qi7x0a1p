class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x=point[0], y=point[1];
        cnt[y][x]++;
    }
    
    int count(vector<int> point) {
        int ans=0, x=point[0], y=point[1];
        if(!cnt.contains(y)) return 0;
        for(auto&[col, colCnt]:cnt){
            if(col!=y){
                int d=col-y;
                int a=colCnt.contains(x)?colCnt[x]:0;
                int b=cnt[y].contains(x+d)?cnt[y][x+d]:0;
                int c=colCnt.contains(x+d)?colCnt[x+d]:0;
                ans+=(a*b*c);
                b=cnt[y].contains(x-d)?cnt[y][x-d]:0;
                c=colCnt.contains(x-d)?colCnt[x-d]:0;
                ans+=(a*b*c);
            }
        }
        return ans;
    }
};
